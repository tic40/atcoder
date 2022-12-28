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

  // a1 が条件を満たしているかをチェックする関数
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

  // dp[i][j] := i行目まで決めて、j(4状態)のときの最小手数
  // 4状態: 今チェックしている行(a1)と、一つ次の行(a2) の組み合わせ4通り
  // 00, 01, 10, 11: 1のときフリップする
  vector<int> dp(4,INF);
  REP(s,4) {
    vector<int> a0(w, -1);
    auto a1 = get(0, s&2);
    auto a2 = get(1, s&1);
    if (check(a0,a1,a2)) dp[s] = __builtin_popcount(s);
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