#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;
using P = pair<int,int>;
const int INF = numeric_limits<int>::max();

struct Edge {
  int u,v;
  ll w;
};

vector<P> query(const vector<int>& c) {
  cout << "? " << c.size();
  for (int v: c) cout << " " << v;
  cout << endl;
  cout.flush();

  vector<P> res;
  REP(i,(int)c.size()-1) {
    int u, v; cin >> u >> v;
    res.emplace_back(u,v);
  }
  return res;
}

void answer(const vector<vector<int>>& groups, const vector<vector<P>>& edges) {
  cout << "!" << endl;
  REP(i,(int)groups.size()) {
    for (int v : groups[i]) cout << v << " ";
    cout << endl;
    for (auto [u,v]: edges[i]) cout << u << " " << v << endl;
  }
}

ll compute_dist(int i, int j, const vector<int>& x, const vector<int>& y) {
  ll dx = (ll)x[i] - x[j];
  ll dy = (ll)y[i] - y[j];
  return dx*dx + dy*dy;
}

vector<P> compute_mst(const vector<int>& group, const vector<int>& x, const vector<int>& y) {
  int sz = group.size();
  vector<Edge> edges;
  REP(i,(int)sz) for (int j = i+1; j < sz; j++) {
    ll d = compute_dist(group[i],group[j],x,y);
    edges.push_back({group[i],group[j],d});
  }

  sort(edges.begin(), edges.end(), [](const Edge& a, const Edge& b){ return a.w < b.w; });

  dsu uf(sz);
  unordered_map<int,int> mp;
  REP(i,(int)sz) mp[group[i]] = i;

  vector<P> res;
  for (auto &e: edges) {
    int u_idx = mp[e.u];
    int v_idx = mp[e.v];
    if (!uf.same(u_idx, v_idx)) {
      uf.merge(u_idx, v_idx);
      if(e.u > e.v) swap(e.u, e.v);
      res.emplace_back(e.u, e.v);
    }
    if ((int)res.size() == sz - 1) break;
  }
  return res;
}

int main() {
  int n, m, q, l, w;
  cin >> n >> m >> q >> l >> w;

  vector<int> g(m);
  REP(i,m) cin >> g[i];
  vector<int> lx(n), rx(n), ly(n), ry(n);
  REP(i,n) cin >> lx[i] >> rx[i] >> ly[i] >> ry[i];

  // 各都市の中心座標
  vector<int> cx(n), cy(n);
  REP(i,n) {
    cx[i] = (lx[i] + rx[i]) / 2;
    cy[i] = (ly[i] + ry[i]) / 2;
  }

  // 全都市の重心を求める
  double sum_x = 0, sum_y = 0;
  REP(i,n) { sum_x += cx[i]; sum_y += cy[i]; }
  double center_x = sum_x / n;
  double center_y = sum_y / n;

  // 都市を極角でソートする
  vector<int> cities(n);
  iota(cities.begin(), cities.end(), 0);
  sort(cities.begin(), cities.end(), [&](int i, int j) {
      double angle_i = atan2(cy[i] - center_y, cx[i] - center_x);
      double angle_j = atan2(cy[j] - center_y, cx[j] - center_x);
      return angle_i < angle_j;
  });

  // 都市をグループに分割
  vector<vector<int>> groups;
  int start_idx = 0;
  for (int v: g) {
    vector<int> group(cities.begin() + start_idx, cities.begin() + start_idx + v);
    groups.push_back(group);
    start_idx += v;
  }

  vector edges(m,vector<P>());
  REP(k,m) edges[k] = compute_mst(groups[k], cx, cy);

  answer(groups, edges);
  return 0;
}

