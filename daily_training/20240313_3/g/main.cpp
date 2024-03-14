#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;
const ll LINF = numeric_limits<ll>::max();

int main() {
  int n; cin >> n;
  vector<ll> x(n),y(n),p(n);
  REP(i,n) cin >> x[i] >> y[i] >> p[i];

  vector dp(n, vector<ll>(n));
  REP(i,n) REP(j,n) {
    dp[i][j] = abs(x[i]-x[j]) + abs(y[i]-y[j]);
    dp[i][j] = (dp[i][j]+(p[i]-1)) / p[i];
  }

  REP(k,n) REP(i,n) REP(j,n) dp[i][j] = min(dp[i][j], max(dp[i][k],dp[k][j]));

  ll ans = LINF;
  REP(i,n) {
    ll now = 0;
    REP(j,n) now = max(now,dp[i][j]);
    ans = min(ans,now);
  }

  cout << ans << endl;
  return 0;
}