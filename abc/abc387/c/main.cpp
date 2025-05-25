#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;

int main() {
  string l,r; cin >> l >> r;

  auto solve = [&](string s) {
    int n = s.size();
    /*
     dp[i][j][k][t]
       i 桁目
       j 未満フラグ
       k 先頭桁の数
       t 先頭桁がまだ決まっているかどうか(0が続いていない)
    */
    vector dp(n+1,vector(2,vector(10,vector<ll>(2))));

    dp[1][1][0][0] = 1;
    for(int k = 1; k < s[0]-'0'; k++) dp[1][1][k][1] = 1;
    dp[1][0][s[0]-'0'][1] = 1;

    for(int i = 1; i < n; i++) REP(j,2) REP(k,10) REP(t,2) {
      REP(d,10) {
        int nj = j;
        int nk = k;
        int nt = t;
        if (t == 1 && k <= d) continue;
        if (t == 0) {
          if (k == 0 && d > 0) {
            nt = 1;
            nk = d;
          }
        }
        if (j == 0) {
          if (s[i]-'0' < d) continue;
          if (s[i]-'0' > d) nj = 1;
        }
        dp[i+1][nj][nk][nt] += dp[i][j][k][t];
      }
    }
    return dp;
  };

  auto dp1 = solve(r);
  auto dp2 = solve(l);
  ll ans = 0;

  int n = r.size();
  for(int k = 0; k < 10; k++) ans += dp1[n][0][k][1] + dp1[n][1][k][1];
  n = l.size();
  for(int k = 0; k < 10; k++) ans -= dp2[n][1][k][1];

  cout << ans << endl;
  return 0;
}