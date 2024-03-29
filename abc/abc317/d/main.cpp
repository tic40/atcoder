#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;
const ll LINF = numeric_limits<ll>::max();
template<class T> void chmin(T& a, T b) { a = min(a,b); }

int main() {
  int n; cin >> n;
  vector<int> x(n),y(n),z(n);
  REP(i,n) cin >> x[i] >> y[i] >> z[i];

  vector dp(n+1,vector<ll>(1e5+1,LINF));
  dp[0][0] = 0;
  REP(i,n) REP(j,1e5) {
    if (dp[i][j] == LINF) continue;
    chmin(dp[i+1][j],dp[i][j]);
    if (x[i] > y[i]) chmin(dp[i+1][j+z[i]], dp[i][j]);
    if (x[i] < y[i]) chmin(dp[i+1][j+z[i]], dp[i][j] + (y[i]-x[i])/2+1);
  }
  int mid = accumulate(z.begin(),z.end(),0LL) / 2 + 1;
  ll ans = LINF;
  for(int i = mid; i <= 1e5; i++) chmin(ans,dp[n][i]);
  cout << ans << endl;
  return 0;
}