#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<(int)(n);i++)
using mint = modint998244353;

mint dp[1000005][10];

int main() {
  int n; cin >> n;
  for(int i = 1; i <= 9; i++) dp[1][i] = 1;

  for(int i = 1; i < n; i++) {
    for(int j = 1; j <= 9; j++) {
      dp[i+1][j] += dp[i][j];
      dp[i+1][j] += dp[i][j+1];
      dp[i+1][j] += dp[i][j-1];
    }
  }

  mint ans = 0;
  REP(i,10) ans += dp[n][i];
  cout << ans.val() << endl;

  return 0;
}