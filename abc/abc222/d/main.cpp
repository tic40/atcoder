#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(int)(n);i++)
using ll = long long;
const int MOD = 998244353;

int n;
vector<ll> a,b;
ll dp[3005][3005]; // [i番目][j以下]

void solve() {
  REP(i,3001) dp[0][i] = 1;
  REP(i,n) {
    ll l = a[i];
    ll r = b[i];
    for(ll j = 0; j <= 3000; j++) {
      if (j < l) {
        dp[i+1][j] = dp[i+1][j-1];
      } else if (j <= r) {
        dp[i+1][j] += dp[i+1][j-1];
        dp[i+1][j] += dp[i][j];
        dp[i+1][j] %= MOD;
      } else {
        dp[i+1][j] = dp[i+1][j-1];
      }
    }
  }

  cout << dp[n][3000] << endl;
  return;
}

int main() {
  cin >> n;
  a.resize(n);
  b.resize(n);
  REP(i,n) cin >> a[i];
  REP(i,n) cin >> b[i];

  solve();
  return 0;
}