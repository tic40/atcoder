#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'
using ll = long long;
using mint = modint998244353;

int main() {
  int n; cin >> n;
  vector<int> a(n);
  REP(i,n) cin >> a[i];

  // m個選ぶ
  mint ans = 0;
  for(int m = 1; m <= n; m++) {
    vector dp(n+2, vector(n+2, vector<mint>(n+2)));
    // dp[i][j][k] := iからj項選ぶ
    dp[0][0][0] = 1;
    REP(i,n) REP(j,m+1) REP(k,m) {
      // 選ばない
      dp[i+1][j][k] += dp[i][j][k];
      // 選ぶ
      dp[i+1][j+1][(k + a[i]) % m] += dp[i][j][k];
    }
    ans += dp[n][m][0];
  }

  cout << ans.val() << endl;
  return 0;
}