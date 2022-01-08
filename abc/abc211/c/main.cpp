#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
using ll = long long;
const int MOD = 1e9+7;
const string t = "chokudai";

int main() {
  string s; cin >> s;
  int n = s.size();
  vector<vector<int>> dp(n+1, vector<int>(9));
  REP(i,n+1) dp[i][0] = 1;

  REP(i,n) REP(j,8) {
    dp[i+1][j+1] = dp[i][j+1];
    if (s[i] == t[j]) {
      dp[i+1][j+1] += dp[i][j];
      dp[i+1][j+1] %= MOD;
    }
  }
  cout << dp[n][8] << endl;
  return 0;
}