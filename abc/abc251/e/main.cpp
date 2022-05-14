#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
using ll = long long;
const ll LINF = 1e18+5;

int main() {
  int n; cin >> n;
  vector<int> a(n);
  REP(i,n) cin >> a[i];

  vector<vector<ll>> dp(2, vector<ll>(2));
  dp[1][0] = LINF;
  REP(i,n) {
    vector<vector<ll>> ndp(2, vector<ll>(2));
    ndp[0][0] = dp[1][0];
    ndp[1][0] = min(dp[1][0],dp[0][0]) + a[i];

    ndp[0][1] = dp[1][1];
    ndp[1][1] = min(dp[1][1],dp[0][1]) + a[i];
    swap(dp,ndp);
  }

  cout << min(dp[1][1], min(dp[1][0], dp[0][0])) << endl;
  return 0;
}