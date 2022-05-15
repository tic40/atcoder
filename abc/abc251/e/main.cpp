#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
using ll = long long;
const ll LINF = 1e18+5;

int main() {
  int n; cin >> n;
  vector<int> a(n);
  REP(i,n) cin >> a[i];

  vector<vector<ll>> dp(2,vector<ll>(2));
  REP(i,n) {
    vector<vector<ll>> p(2,vector<ll>(2));
    p[0][0] = i == 0 ? LINF : dp[1][0];
    p[1][0] = min(dp[0][0],dp[1][0]) + a[i];

    p[0][1] = dp[1][1];
    p[1][1] = min(dp[0][1],dp[1][1]) + a[i];
    swap(dp,p);
  }

  cout << min(min(dp[0][0],dp[1][0]), dp[1][1]) << endl;
  return 0;
}