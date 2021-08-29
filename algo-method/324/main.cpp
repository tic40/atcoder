#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)

int dp[4][4];

int main() {
  REP(i,4) {
    int a; cin >> a;
    dp[0][i] = a;
  }

  REP(i,4) REP(j,4) {
    if (i == 0) continue;
    dp[i][j] += dp[i-1][j];
    if (j-1 >= 0) dp[i][j] += dp[i-1][j-1];
    if (j+1 <= 3) dp[i][j] += dp[i-1][j+1];
  }

  cout << dp[3][3] << endl;
  return 0;
}