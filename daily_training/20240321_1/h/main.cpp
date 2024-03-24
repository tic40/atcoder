#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using mint = modint998244353; // modint1000000007;

int main() {
  int n,m; cin >> n >> m;
  // dp[i][j]
  // i: iまでみたとき
  // j: 1 1番目と同じ色, 0 1番目と異なる色
  vector dp(n+1,vector<mint>(2));
  dp[1][1] = m;
  for(int i = 1; i < n; i++) REP(j,2) {
    if (j == 1) {
      dp[i+1][0] += dp[i][j] * (m-1);
    } else {
      dp[i+1][1] += dp[i][j];
      dp[i+1][0] += dp[i][j] * (m-2);
    }
  }
  cout << dp[n][0].val() << endl;
  return 0;
}