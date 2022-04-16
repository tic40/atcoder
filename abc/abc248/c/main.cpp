#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
using mint = modint998244353;

int main() {
  int n,m,k; cin >> n >> m >> k;
  vector<vector<mint>> dp(n+1,vector<mint>(n*m+1));

  dp[0][0]=1;
  REP(i,n) REP(now,k+1) {
    for(int nx = now+1; nx <= min(k,now+m); nx++) {
      dp[i+1][nx] += dp[i][now];
    }
  }

  mint ans = 0;
  REP(i,k+1) ans += dp[n][i];
  cout << ans.val() << endl;
  return 0;
}