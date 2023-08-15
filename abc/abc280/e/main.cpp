#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using mint = modint998244353;

int main() {
  int n, _p;
  cin >> n >> _p;
  mint p = (mint)_p / 100;
  mint q = (mint)1 - p;

  vector<mint> dp(n+1);
  dp[0] = 0;
  for(int i = 1; i <= n; i++) {
    dp[i] = 1;
    // 1 減らす p
    dp[i] += dp[max(0,i-2)] * p;
    // 2 減らす 1-p
    dp[i] += dp[i-1] * q;
  }

  cout << dp[n].val() << endl;
  return 0;
}