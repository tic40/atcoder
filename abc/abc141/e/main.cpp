#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n; string s; cin >> n >> s;

  // dp[i][j] := i からと j から初めたときに一致する最大の長さ
  // 後ろから埋めていく
  vector dp(n+1,vector<int>(n+1));
  for(int i = n-1; i >= 0; i--) for(int j = n-1; j >= 0; j--) {
    dp[i][j] = s[i]!=s[j] ? 0 : dp[i+1][j+1]+1;
  }

  int ans = 0;
  REP(i,n) for (int j = i+1; j < n; j++) ans = max(ans,min(dp[i][j],j-i));
  cout << ans << endl;
  return 0;
}