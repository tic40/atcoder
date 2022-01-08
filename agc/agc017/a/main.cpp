#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
using ll = long long;

ll dp[51][5005];
int main() {
  int n,p;
  cin >> n >> p;
  vector<int> a(n);
  REP(i,n) cin >> a[i];

  dp[0][0] = 1;
  REP(i,n) {
    REP(j,5001-a[i]) {
      dp[i+1][j] += dp[i][j];
      dp[i+1][j+a[i]] += dp[i][j];
    }
  }

  ll ans = 0;
  REP(j,5001) if (j % 2 == p) ans += dp[n][j];
  cout << ans << endl;
  return 0;
}