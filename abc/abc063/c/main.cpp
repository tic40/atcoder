#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
using ll = long long;

// dp[問題数][配点]
int dp[105][10005];

int main() {
  int n; cin >> n;
  int a[n]; REP(i,n) cin >> a[i];

  int ans = 0;
  dp[0][0]=1;
  REP(i,n) {
    REP(j,10005) {
      if (dp[i][j]) {
        dp[i+1][j] = 1;
        dp[i+1][j+a[i]] = 1;
      }

      if (i<n-1) continue;
      if (j%10==0) dp[i+1][j] = 0;
      if ((j+a[i])%10==0) dp[i+1][j+a[i]] = 0;
    }
  }
  REP(i,10005) if (dp[n][i]) ans=i;
  cout << ans << endl;
  return 0;
}
