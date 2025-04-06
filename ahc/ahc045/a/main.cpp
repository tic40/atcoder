#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;
using P = pair<int,int>;
const int INF = numeric_limits<int>::max();

vector<P> query(const vector<int>& c) {
  cout << "? " << c.size();
  for (int v : c) cout << " " << v;
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
  for (size_t i = 0; i < groups.size(); ++i) {
    for (int v : groups[i]) cout << v << " ";
    cout << endl;
    for (auto [u, v] : edges[i]) cout << u << " " << v << endl;
  }
}

int main() {
  int n, m, q, l, w; cin >> n >> m >> q >> l >> w;

  vector<int> g(m);
  REP(i,m) cin >> g[i];
  vector<int> lx(n), rx(n), ly(n), ry(n);
  REP(i,n) cin >> lx[i] >> rx[i] >> ly[i] >> ry[i];

  // 中心座標を計算
  vector<int> x(n), y(n);
  REP(i,n) {
    x[i] = (lx[i] + rx[i]) / 2;
    y[i] = (ly[i] + ry[i]) / 2;
  }

  // 都市を中心座標でソート
  vector<int> cities(n);
  iota(cities.begin(), cities.end(), 0);
  sort(cities.begin(), cities.end(), [&](int i, int j) { return P(x[i], y[i]) < P(x[j], y[j]); });

  // 都市をグループに分割
  vector<vector<int>> groups;
  int start_idx = 0;
  for (int v: g) {
    vector<int> group(cities.begin() + start_idx, cities.begin() + start_idx + v);
    groups.push_back(group);
    start_idx += v;
  }

  vector<vector<P>> edges(m);
  REP(k,m) {
    for (int i = 0; i < g[k] - 1; i += 2) {
      if (i < g[k] - 2) {
        vector<int> subvec = {groups[k][i], groups[k][i + 1], groups[k][i + 2]};
        auto ret = query(subvec);
        edges[k].insert(edges[k].end(), ret.begin(), ret.end());
      } else {
        edges[k].emplace_back(groups[k][i], groups[k][i + 1]);
      }
    }
  }

  answer(groups, edges);
  return 0;
}
