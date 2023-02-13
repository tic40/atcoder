#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;

int main() {
  int h,w; cin >> h >> w;
  vector<string> c(h);
  REP(i,h) cin >> c[i];

  vector dp(h,vector<ll>(w));
  dp[0][0] = 1;
  REP(i,h) REP(j,w) {
    if (c[i][j] == '#') continue;
    if (i-1 >= 0) dp[i][j] += dp[i-1][j];
    if (j-1 >= 0) dp[i][j] += dp[i][j-1];
  }

  cout << dp[h-1][w-1] << endl;
  return 0;
}