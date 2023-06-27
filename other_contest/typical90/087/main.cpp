#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;

int main() {
  int n,p,k; cin >> n >> p >> k;
  vector a(n,vector<ll>(n));
  REP(i,n) REP(j,n) cin >> a[i][j];

  auto solve = [&](int key) {
    ll l = 1, r = 1e10;
    REP(_,40) {
      ll mid = (l+r) / 2;
      auto dp = a;
      REP(i,n) REP(j,n) if (dp[i][j] == -1) dp[i][j] = mid;
      REP(k,n) REP(i,n) REP(j,n) dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
      int cnt = 0;
      REP(i,n) for(int j = i+1; j < n; j++) if (dp[i][j] <= p) cnt++;
      if (cnt <= key) r = mid;
      else l = mid;
    }
    return r;
  };

  ll ans = solve(k-1) - solve(k);
  if (ans >= 1e9) cout << "Infinity" << endl;
  else cout << ans << endl;
  return 0;
}