#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;

int main() {
  string s; cin >> s;
  const int n = s.size();
  const int m = n*9;
  // dp[i][j][k][l]
  //  i 番目までみたとき
  //  j 未満フラグ
  //  k 桁和が k のとき
  //  l 現在の数を 桁和(x)で割った余り
  vector dp(n+1,vector(2,vector(m+1,vector<ll>(m+1))));

  ll ans = 0 ;
  for(int x = 1; x <= m; x++) {
    REP(i,n) REP(j,2) REP(k,m+1) REP(l,x) dp[i][j][k][l] = 0;
    dp[0][0][0][0] = 1;

    REP(i,n) REP(j,2) REP(k,m+1) REP(l,x) {
      REP(d,10) {
        int nj = j;
        int nk = k + d;
        int nl = (l * 10 + d) % x;
        if (nk > x) continue;
        if (j == 0) {
          if (s[i]-'0' < d) continue;
          if (s[i]-'0' > d) nj = 1;
        }
        dp[i+1][nj][nk][nl] += dp[i][j][k][l];
      }
    }
    ans += dp[n][0][x][0] + dp[n][1][x][0];
  }
  cout << ans << endl;
  return 0;
}