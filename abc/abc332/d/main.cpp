#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;
const int INF = numeric_limits<int>::max();

int main() {
  int h,w; cin >> h >> w;
  vector a(h,vector<int>(w));
  vector b(h,vector<int>(w));
  REP(i,h) REP(j,w) cin >> a[i][j];
  REP(i,h) REP(j,w) cin >> b[i][j];

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
  return 0;
}
