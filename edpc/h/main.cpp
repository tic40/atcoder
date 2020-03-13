#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
typedef long long ll;

ll dp[1010][1010];
const int mod = 1e+9+7;

int main() {
  int h,w; cin >> h >> w;
  string a[h];
  REP(i,h) cin >> a[i];

  dp[0][0] = 1;
  REP(i,h) REP(j,w) {
    if (a[i+1][j] == '.') {
      if (j > 0) dp[i+1][j] = max(dp[i+1][j], dp[i][j]+dp[i+1][j-1]);
      else dp[i+1][j] = max(dp[i+1][j], dp[i][j]);
      dp[i+1][j]%=mod;
    }
    if (a[i][j+1] == '.') {
      if (i > 0) dp[i][j+1] = max(dp[i][j+1], dp[i][j]+dp[i-1][j+1]);
      else dp[i][j+1] = max(dp[i][j+1], dp[i][j]);
      dp[i][j+1]%=mod;
    }
  }
  cout << dp[h-1][w-1] << endl;
}
