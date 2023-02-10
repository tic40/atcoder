#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n,s; cin >> n >> s;
  vector<int> a(n);
  REP(i,n) cin >> a[i];

  vector dp(n+1,vector<bool>(s+1));
  dp[0][0] = true;
  REP(i,n) REP(j,s+1) {
    dp[i+1][j] = dp[i][j];
    if (j - a[i] >= 0) dp[i+1][j] = dp[i][j] || dp[i][j-a[i]];
  }

  if (!dp[n][s]) {
    cout << -1 << endl;
    return 0;
  }

  int now = s;
  vector<int> ans;
  for(int i = n; i > 0; i--) {
    if (now - a[i-1] >= 0 && dp[i][now-a[i-1]]) {
      now -= a[i-1];
      ans.push_back(i);
    }
  }

  reverse(ans.begin(),ans.end());
  cout << ans.size() << endl;
  for(int v: ans) cout << v << " ";
  return 0;
}