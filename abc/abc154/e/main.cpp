#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;

int main() {
  string s; int k; cin >> s >> k;

  int n = s.size();
  vector dp(n+1, vector(2, vector<ll>(k+1)));
  dp[0][0][0] = 1;

  REP(i,n) REP(j,2) REP(p,k+1) {
    int d = s[i] - '0';
    REP(x,10) {
      int nj = j;
      int np = x == 0 ? p : p+1;
      if (np > k) continue;
      if (j == 0) {
        if (d < x) continue;
        if (d > x) nj = 1;
      }
      dp[i+1][nj][np] += dp[i][j][p];
    }
  }

  cout << dp[n][1][k] + dp[n][0][k] << endl;
  return 0;
}