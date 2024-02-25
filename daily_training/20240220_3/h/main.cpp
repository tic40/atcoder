#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using mint = modint998244353; // modint1000000007;

int main() {
  int n,m,k; cin >> n >> m >> k;

  vector dp(n+1,vector<mint>(m+1));
  for(int i = 1; i <= m; i++) dp[0][i] = 1;

  for(int i = 0; i < n-1; i++) {
    vector<mint> s(m+2); // 累積和
    REP(j,m+1) s[j+1] = s[j] + dp[i][j];
    for(int j = 1; j <= m; j++) {
      if (k == 0) {
        dp[i+1][j] += s[m+1] - s[0];
        continue;
      }
      // j-x >= k
      // -x >= k-j
      // x <= j-k
      if (j-k >= 1) dp[i+1][j] += s[j-k+1] - s[0];
      // x-j >= k
      // x >= k+j
      if (k+j <= m) dp[i+1][j] += s[m+1] - s[k+j];
    }
  }

  mint ans = 0;
  REP(i,m+1) ans += dp[n-1][i];
  cout << ans.val() << endl;
  return 0;
}