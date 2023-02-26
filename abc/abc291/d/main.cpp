#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using mint = modint998244353;

int main() {
  int n; cin >> n;
  vector<int> a(n),b(n);
  REP(i,n) cin >> a[i] >> b[i];

  vector dp(n, vector<mint>(2));
  dp[0][0] = 1;
  dp[0][1] = 1;
  REP(i,n-1) {
    if (a[i] != a[i+1]) dp[i+1][0] += dp[i][0];
    if (b[i] != b[i+1]) dp[i+1][1] += dp[i][1];
    if (a[i] != b[i+1]) dp[i+1][1] += dp[i][0];
    if (b[i] != a[i+1]) dp[i+1][0] += dp[i][1];
  }

  mint ans = dp[n-1][0] + dp[n-1][1];
  cout << ans.val() << endl;
  return 0;
}