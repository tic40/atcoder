#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
typedef long long ll;

int dp[100001][3];

int main() {
  int n; cin >> n;
  int a[n][3];
  REP(i,n) REP(j,3) cin >> a[i][j];

  REP(i,n) {
    REP(j,3) {
      REP(k,3) {
        if (j==k) continue;
        dp[i+1][j] = max(dp[i+1][j], dp[i][k] + a[i][j]);
      }
    }
  }
  int ans = 0;
  REP(i,3) ans = max(ans, dp[n][i]);
  cout << ans << endl;
}