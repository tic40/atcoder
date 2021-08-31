#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)

int dp[1005][1005];

int main() {
  string s,t;
  cin >> s >> t;

  REP(i,s.size()) {
    REP(j,t.size()) {
      dp[i+1][j+1] = max(dp[i+1][j], dp[i][j+1]);
      if (s[i] == t[j]) dp[i+1][j+1] = dp[i][j] + 1;
    }
  }

  cout << dp[s.size()][t.size()] << endl;
  return 0;
}