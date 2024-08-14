
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using mint = modint998244353;

int main() {
  int n,t; cin >> n >> t;
  mint p = (mint)t / 100;
  mint q = (mint)1-p;

  vector<mint> dp(n+1);
  for(int i = 1; i <= n; i++) {
    dp[i] = 1;
    if (i-2 >= 0) dp[i] += dp[i-2] * p;
    if (i-1 >= 0) dp[i] += dp[i-1] * q;
  }
  cout << dp[n].val() << endl;
  return 0;
}