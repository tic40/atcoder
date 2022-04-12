#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)

int main() {
  int n,s; cin >> n >> s;
  vector<int> a(n),b(n);
  REP(i,n) cin >> a[i] >> b[i];

  vector<vector<bool>> dp(n+1, vector<bool>(s+1, false));
  dp[0][0] = true;
  REP(i,n) REP(j,s+1) {
    if (dp[i][j] && j + a[i] <= s) dp[i+1][j+a[i]] = true;
    if (dp[i][j] && j + b[i] <= s) dp[i+1][j+b[i]] = true;
  }

  if (!dp[n][s]) { cout << "Impossible" << endl; return 0; }

  int now = s;
  string ans;
  for(int i = n-1; 0 <= i; i--) {
    if (0 <= now - a[i] && dp[i][now - a[i]]) {
      now -= a[i];
      ans += 'A';
    } else {
      now -= b[i];
      ans += 'B';
    }
  }

  reverse(ans.begin(),ans.end());
  cout << ans << endl;
  return 0;
}