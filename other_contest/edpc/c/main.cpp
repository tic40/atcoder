#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)

int main() {
  int n; cin >> n;
  vector<vector<int>> g(n,vector<int> (3));
  REP(i,n) cin >> g[i][0] >> g[i][1] >> g[i][2];

  vector<int> dp(3);
  REP(i,n) {
    vector<int> p(3);
    REP(from,3) REP(to,3) {
      if (from != to) p[to] = max(p[to], dp[from] + g[i][to]);
    }
    swap(p,dp);
  }

  int ans = 0;
  REP(i,3) ans = max(ans,dp[i]);
  cout << ans << endl;
  return 0;
}
