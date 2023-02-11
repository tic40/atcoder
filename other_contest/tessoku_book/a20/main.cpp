#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  string s,t; cin >> s >> t;
  int ss = s.size(), ts = t.size();
  vector dp(ss+1,vector<int>(ts+1));

  REP(i,ss) REP(j,ts) {
    if (s[i] == t[j]) dp[i+1][j+1] = dp[i][j]+1;
    else dp[i+1][j+1] = max(dp[i+1][j],dp[i][j+1]);
  }

  cout << dp[ss][ts] << endl;
  return 0;
}