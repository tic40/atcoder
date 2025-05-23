#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using mint = modint1000000007;

int main() {
  string s; cin >> s;
  int n = s.size();
  vector dp(n+1,vector<mint>(2));
  dp[0][0] = 1;

  REP(i,n) REP(j,2) {
    REP(x,2) REP(y,2) if ((x&y) != 1) {
      int nj = j;
      if (j == 0) {
        if (s[i]-'0' < (x+y)) continue;
        if (s[i]-'0' > (x+y)) nj = 1;
      }
      dp[i+1][nj] += dp[i][j];
    }
  }
  cout << (dp[n][0]+dp[n][1]).val() << endl;
  return 0;
}