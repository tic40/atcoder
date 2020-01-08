#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
typedef long long ll;

ll dp[51][51][2510];
ll a[51];

int main() {
  int n, x;
  ll ans = 0;
  cin>>n>>x;
  REP(i, n) cin>>a[i];
  dp[0][0][0] = 1;

  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= i; j++) {
      for (int k = 0; k <= 2500; k++) {
        dp[i][j][k] = dp[i - 1][j][k];
        if (j > 0 && k >= a[i - 1])
          dp[i][j][k] += dp[i - 1][j - 1][k - a[i - 1]];
      }
    }
  }
  for (int j = 1; j <= n; j++) if (x * j < 2510) ans += dp[n][j][x * j];
  cout << ans << endl;
}