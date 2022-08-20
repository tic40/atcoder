#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'

int main() {
  int n,m,q; cin >> n >> m >> q;
  vector g(n,vector<int>(n));
  REP(i,m) {
    int l,r; cin >> l >> r;
    l--; r--;
    g[l][r]++;
  }

  // 2次元累積和
  vector dp(n+1,vector<int>(n+1));
  REP(i,n) REP(j,n) {
     dp[i+1][j+1] = g[i][j] + dp[i+1][j] + dp[i][j+1] - dp[i][j];
  }

  REP(i,q) {
    int l,r; cin >> l >> r;
    l--; r--;
    cout << dp[r+1][r+1] - dp[l][r+1] - dp[r+1][l] + dp[l][l] << endl;
  }
  return 0;
}