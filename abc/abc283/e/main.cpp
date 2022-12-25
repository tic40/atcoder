#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
const int INF = 1e9;

int main() {
  int h,w; cin >> h >> w;
  vector a(h, vector<int>(w));
  REP(i,h) REP(j,w) cin >> a[i][j];

  auto get = [&](int i, bool flip) {
    vector<int> res = a[i];
    if (flip) REP(i,w) res[i] ^= 1;
    return res;
  };

  auto check = [&](
    const vector<int>& a0,
    const vector<int>& a1,
    const vector<int>& a2
  ) {
    REP(i,w) {
      if (a0[i] == a1[i]) continue;
      if (a2[i] == a1[i]) continue;
      if (i && a1[i-1] == a1[i]) continue;
      if (i+1 < w && a1[i+1] == a1[i]) continue;
      return false;
    }
    return true;
  };

  vector<int> dp(4,INF);
  REP(s,4) {
    vector<int> a0(w, -1);
    auto a1 = get(0, s&2);
    auto a2 = get(1, s&1);
    int cnt = 0;
    if (s&1) cnt++;
    if (s&2) cnt++;
    if (check(a0,a1,a2)) dp[s] = cnt;
  }

  for(int i = 2; i < h; i++) {
    vector<int> p(4,INF);
    swap(dp,p);
    REP(s,4) {
      auto a0 = get(i-2, s&2);
      auto a1 = get(i-1, s&1);
      REP(x,2) {
        auto a2 = get(i,x);
        if (check(a0,a1,a2)) {
          int ns = (s&1) << 1 | x;
          dp[ns] = min(dp[ns],p[s]+x);
        }
      }
    }
  }

  int ans = INF;
  REP(s,4) {
    auto a0 = get(h-2,s&2);
    auto a1 = get(h-1,s&1);
    vector<int> a2(w,-1);
    if (check(a0,a1,a2)) ans = min(ans, dp[s]);
  }

  cout << (ans == INF ? -1 : ans) << endl;
  return 0;
}