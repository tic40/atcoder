#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
using ll = long long;

int main() {
  int n; cin >> n;
  vector<int> x(n),y(n),p(n);
  REP(i,n) cin >> x[i] >> y[i] >> p[i];

  ll ok = 4e9, ng = 0;
  while(abs(ok-ng) > 1) {
    ll mid = (ok+ng)/2;

    auto judge = [&]() {
      // dp[i][j] := iからjへの移動が可能であれば1
      vector dp(n, vector<int>(n));

      REP(i,n) REP(j,n) {
        ll dist = (ll)abs(x[i]-x[j]) + abs(y[i]-y[j]);
        if (mid*p[i] >= dist) dp[i][j] = 1;
      }
      // warshall floyd
      REP(k,n) REP(i,n) REP(j,n) {
        dp[i][j] |= dp[i][k] & dp[k][j];
      }

      // 支点をiと置いて、全てに移動可能であればtrue
      REP(i,n) {
        bool ok = true;
        REP(j,n) if (dp[i][j] == 0) ok = false;
        if (ok) return true;
      }
      return false;
    };

    if (judge()) ok = mid;
    else ng = mid;
  }

  cout << ok << endl;
  return 0;
}
