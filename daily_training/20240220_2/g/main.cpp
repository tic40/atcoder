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

  vector<int> dp(x+1); // dp[i] := i に到達可能かどうか
  dp[0] = 1;
  REP(i,x+1) {
    if (b[i]) continue;
    REP(j,n) {
      int v = i - a[j];
      if (v < 0) break;
      dp[i] |= dp[v];
    }
  }
  cout << (dp[x] ? "Yes" : "No") << endl;
  return 0;
}