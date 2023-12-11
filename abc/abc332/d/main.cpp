#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;
using vvi = vector<vector<int>>;
const int INF = numeric_limits<int>::max();

int main() {
  int h,w; cin >> h >> w;
  vector a(h,vector<int>(w));
  vector b(h,vector<int>(w));
  REP(i,h) REP(j,w) cin >> a[i][j];
  REP(i,h) REP(j,w) cin >> b[i][j];

  // 順列全部試して転倒数で最小手数を求める
  auto solve1 = [&]() -> void {
    auto f = [](int x) {
      vector<vector<int>> res;
      vector<int> b(x);
      REP(i,x) b[i] = i;
      do {
        res.push_back(b);
      } while (next_permutation(b.begin(), b.end()));
      return res;
    };

    // 転倒数
    auto f2 = [](vector<int>& v) {
      int res = 0, n = v.size();
      fenwick_tree<int> fw(n);
      REP(i,n) {
        fw.add(v[i],1);
        res += fw.sum(v[i]+1,n);
      }
      return res;
    };

    auto pv = f(h);
    auto ph = f(w);
    int ans = INF;
    for(auto v1: ph) {
      vector na(h,vector<int>(w));
      REP(j,w) REP(i,h) na[i][j] = a[i][v1[j]];
      for(auto v2: pv) {
        vector na2(h,vector<int>(w));
        REP(i,h) na2[i] = na[v2[i]];

        if (na2 == b) {
          int now = f2(v1) + f2(v2);
          ans = min(ans,now);
        }
      }
    }
    cout << (ans == INF ? -1 : ans) << endl;
  };

  // 解説放送解: BFS
  auto solve2 = [&]() -> void {
    queue<vvi> q;
    map<vvi,int> dist;
    auto push = [&](vvi& s, int d) {
      if (dist.count(s)) return;
      dist[s] = d;
      q.push(s);
    };

    push(a,0);
    while(q.size()) {
      auto s = q.front(); q.pop();
      int d = dist[s];
      REP(i,h-1) {
        vvi ns = s;
        swap(ns[i], ns[i+1]);
        push(ns,d+1);
      }
      REP(j,w-1) {
        vvi ns = s;
        REP(i,h) swap(ns[i][j], ns[i][j+1]);
        push(ns,d+1);
      }
    }

    if (dist.count(b)) cout << dist[b] << endl;
    else cout << -1 << endl;
  };

  // solve1();
  solve2();
  return 0;
}
