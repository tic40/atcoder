#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n,s; cin >> n >> s;
  vector<int> a(n),b(n);
  REP(i,n) cin >> a[i] >> b[i];

  vector dp(n+1,vector<int>(s+1));
  dp[0][0] = 1;
  REP(i,n) REP(j,s+1) {
    if (j-a[i] >= 0) dp[i+1][j] |= dp[i][j-a[i]];
    if (j-b[i] >= 0) dp[i+1][j] |= dp[i][j-b[i]];
  }

  if (dp[n][s] == 0) { cout << "Impossible" << endl; return 0; }

  int now = s;
  string ans = "";
  for(int i = n-1; i >= 0; i--) {
    if (now - a[i] >= 0 && dp[i][now-a[i]]) { ans = 'A' + ans; now -= a[i]; }
    else { ans = 'B' + ans; now -= b[i]; }
  }

  cout << ans << endl;
  return 0;
}