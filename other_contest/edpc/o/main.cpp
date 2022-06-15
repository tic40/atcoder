#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
using ll = long long;
const int MOD = 1e9+7;

int main() {
  int n; cin >> n;
  vector<vector<int>> a(n,vector<int>(n));
  REP(i,n) REP(j,n) cin >> a[i][j];

  vector<ll> dp((1<<n)+1);
  dp[0]=1;
  REP(bit, (1<<n)-1) {
    int i = __builtin_popcount(bit);
    REP(j,n) {
      if ( (bit >> j & 1) == 0 && a[i][j]) {
        int nbit = bit | (1<<j);
        dp[nbit] += dp[bit];
        dp[nbit] %= MOD;
      }
    }
  }

  cout << dp[(1<<n)-1] << endl;
  return 0;
}
