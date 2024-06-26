#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  string s,t; cin >> s >> t;
  int ns = s.size();
  int nt = t.size();

  vector dp(ns+1,vector<int>(nt+1));
  REP(i,ns) REP(j,nt) {
    dp[i+1][j+1] = max({dp[i+1][j], dp[i][j+1], dp[i][j] + (s[i] == t[j] ? 1 : 0)});
  }

  // 最長の長さ cout << dp[ns][nt] << endl;

  int i = ns, j = nt;
  string ans;
  while(0 < i && 0 < j) {
    if (dp[i][j] == dp[i-1][j]) i--;
    else if (dp[i][j] == dp[i][j-1]) j--;
    else {
      i--; j--;
      ans += s[i];
    }
  }

  reverse(ans.begin(),ans.end());
  cout << ans << endl;
  return 0;
}