#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  string s,t; cin >> s >> t;
  int n = s.size(), m = t.size();

  vector dp(n+1, vector<int>(m+1, 1e9));
  REP(i,n) dp[i][0] = i;
  REP(j,m) dp[0][j] = j;

  REP(i,n) REP(j,m) {
    if (s[i] == t[j]) {
      dp[i+1][j+1] = min({ dp[i][j+1]+1, dp[i+1][j]+1, dp[i][j] });
    } else {
      dp[i+1][j+1] = min({ dp[i][j+1]+1, dp[i+1][j]+1, dp[i][j]+1 });
    }
  }

  cout << dp[n][m] << endl;
  return 0;
}