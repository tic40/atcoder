#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
using ll = long long;
const int MOD = 1e9+7;

int main() {
  int h,w; cin >> h >> w;
  vector<string> a(h);
  REP(i,h) cin >> a[i];

  vector<vector<ll>> dp(h+1, vector<ll>(w+1));
  dp[0][0] = 1;
  REP(i,h) REP(j,w) {
    if (a[i][j] == '#') continue;
    dp[i+1][j] += dp[i][j];
    dp[i+1][j] %= MOD;
    dp[i][j+1] += dp[i][j];
    dp[i][j+1] %= MOD;
  }

  cout << dp[h-1][w-1] << endl;
  return 0;
}
