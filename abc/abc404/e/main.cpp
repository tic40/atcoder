#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
const int INF = numeric_limits<int>::max();

int main() {
  int n; cin >> n;
  vector<int> c(n),a(n);
  REP(i,n-1) cin >> c[i+1];
  REP(i,n-1) cin >> a[i+1];

  auto solve = [](vector<int>& c) {
    int n = c.size();
    vector<int> dp(n+1,INF);
    dp[0] = 0;
    REP(i,n) {
      int now = INF;
      REP(j,c[i]) if (0 <= i-j) now = min(now, dp[i-j]);
      dp[i+1] = now+1;
    }
    return dp[n];
  };

  int ans = 0;
  vector<int> nc;
  for(int i = 1; i < n; i++) {
    nc.push_back(c[i]);
    if (a[i]) {
      ans += solve(nc);
      nc.clear();
    }
  }
  cout << ans << endl;
  return 0;
}