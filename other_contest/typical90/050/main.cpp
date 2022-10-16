#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'
using mint = modint1000000007;

int main() {
  int n,l; cin >> n >> l;
  vector<mint> dp(n+1);
  dp[0] = 1;
  for(int i = 1; i <= n; i++) {
    dp[i] = dp[i-1];
    if (i - l >= 0) dp[i] += dp[i-l];
  }
  cout << dp[n].val() << endl;
  return 0;
}