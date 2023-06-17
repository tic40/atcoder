#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;
template<class T> void chmax(T& a, T b) { a = max(a,b); }

int main() {
  int n; cin >> n;
  vector<ll> x(n),y(n);
  REP(i,n) cin >> x[i] >> y[i];

  vector dp(n+1,vector<ll>(2));
  REP(i,n) {
    dp[i+1][0] = dp[i][0];
    dp[i+1][1] = dp[i][1];
    if (x[i] == 0) {
      chmax(dp[i+1][0], dp[i][0] + y[i]);
      chmax(dp[i+1][0], dp[i][1] + y[i]);
    } else {
      chmax(dp[i+1][1], dp[i][0] + y[i]);
    }
  }
  ll ans = max(dp[n][0],dp[n][1]);
  cout << ans << endl;
  return 0;
}