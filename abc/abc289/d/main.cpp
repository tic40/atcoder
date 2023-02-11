#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n; cin >> n;
  vector<int> a(n);
  REP(i,n) cin >> a[i];
  int m; cin >> m;
  vector<bool> b(1e5+1);
  REP(i,m) { int t; cin >> t; b[t] = true; }
  int x; cin >> x;

  vector<bool> dp(x+1);
  dp[0] = true;
  REP(i,x+1) {
    if (b[i]) continue;
    REP(j,n) {
      if (i-a[j] < 0) break;
      dp[i] = dp[i] || dp[i - a[j]];
    }
  }

  cout << (dp[x] ? "Yes" : "No") << endl;
  return 0;
}