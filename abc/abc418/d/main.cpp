#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;

int main() {
  int n; string t; cin >> n >> t;
  // dp[i][j] = i までみて、j で終わる部分文字列の総数
  vector dp(n+1,vector<ll>(2));

  for(int i = n-1; i >= 0; i--) {
    int now = t[i]-'0';
    // 選ぶ
    dp[i][!(now^0)] += dp[i+1][0];
    dp[i][!(now^1)] += dp[i+1][1];
    // 選ばない
    dp[i][now]++;
  }
  ll ans = 0;
  REP(i,n+1) ans += dp[i][1];
  cout << ans << endl;
  return 0;
}