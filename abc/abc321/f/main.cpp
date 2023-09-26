#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using mint = modint998244353;

int main() {
  int q,k; cin >> q >> k;

  vector<mint> dp(k+1);
  dp[0]=1;

  REP(_,q) {
    char c; int x;
    cin >> c >> x;
    if (c == '+') {
      for(int i = k; i >= x; i--) dp[i] += dp[i-x];
    } else {
      for(int i = x; i <= k; i++) dp[i] -= dp[i-x];
    }
    cout << dp[k].val() << endl;
  }
  return 0;
}