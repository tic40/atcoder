#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
using ll = long long;
const ll LINF = 1e18+5;

int main() {
  int n; cin >> n;
  vector<int> a(n);
  REP(i,n) cin >> a[i];

  // 最初を決め打ち
  vector<vector<ll>> dp1(n+1, vector<ll> (2));
  dp1[1][0] = LINF;
  dp1[1][1] = a[0];
  for(int i = 1; i < n; i++) {
    dp1[i+1][0] = dp1[i][1];
    dp1[i+1][1] = min(dp1[i][0], dp1[i][1])+a[i];
  }
  ll ans = min(dp1[n][1], dp1[n][0]);

  // 最後を決め打ち
  vector<vector<ll>> dp2(n+1, vector<ll> (2));
  dp2[0][0] = LINF;
  dp2[0][1] = a[n-1];
  for(int i = 0; i < n-1; i++) {
    dp2[i+1][0] = dp2[i][1];
    dp2[i+1][1] = min(dp2[i][0], dp2[i][1])+a[i];
  }

  ans = min(ans, min(dp2[n-1][1], dp2[n-1][0]));
  cout << ans << endl;

  return 0;
}
