#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'
using ll = long long;
const int INF = numeric_limits<int>::max();

int main() {
  int n; cin >> n;
  vector<int> x(1e5+1),a(1e5+1);
  REP(i,n) {
    int t,_x,_a;
    cin >> t >> _x >> _a;
    x[t] = _x; a[t] = _a;
  }

  // dp[i] := 座標i地点にいるときの最大値
  vector<ll> dp(5,-INF);
  dp[0] = 0;
  REP(i,1e5+1) {
    vector<ll> p(5,-INF);
    p[0] = 0;
    swap(dp,p);

    REP(j,5) {
      // 移動しない
      dp[j] = max(dp[j], p[j]);
      if (x[i] == j) dp[j] = max(dp[j], p[j]+a[i]);

      // -1移動
      if (j > 0) {
        if (x[i] == j) dp[j-1] = max(dp[j-1], p[j]+a[i]);
        else dp[j-1] = max(dp[j-1], p[j]);
      }

      // +1移動
      if (j < 4) {
        if (x[i] == j) dp[j+1] = max(dp[j+1], p[j]+a[i]);
        else dp[j+1] = max(dp[j+1], p[j]);
      }
    }
  }

  ll ans = 0;
  REP(i,5) ans = max(ans, dp[i]);
  cout << ans << endl;
  return 0;
}