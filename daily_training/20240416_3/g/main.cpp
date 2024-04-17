#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;
const ll LINF = numeric_limits<ll>::max();
template<class T> void chmin(T& a, T b) { a = min(a,b); }

int main() {
  int n; cin >> n;
  vector<ll> x(n),y(n),p(n);
  REP(i,n) cin >> x[i] >> y[i] >> p[i];

  vector dp(n, vector<ll>(n,LINF));
  REP(i,n) REP(j,n) dp[i][j] = (abs(x[i]-x[j]) + abs(y[i]-y[j]) + p[i]-1) / p[i];
  REP(k,n) REP(i,n) REP(j,n) dp[i][j] = min(dp[i][j], max(dp[i][k],dp[k][j]));

  ll ans = LINF;
  REP(i,n) chmin(ans, *max_element(dp[i].begin(),dp[i].end()));
  cout << ans << endl;

  return 0;
}