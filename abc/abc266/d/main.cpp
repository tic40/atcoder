#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'
using ll = long long;

int main() {
  int n; cin >> n;
  vector<int> t(n),x(n),a(n);
  REP(i,n) cin >> t[i] >> x[i] >> a[i];

  vector<ll> dp(5,-1); // dp[i] := 座標i地点にいるときの最大値
  dp[0] = 0;
  int now = 0;
  REP(i,1e5+1) {
    vector<ll> p(5,-1);
    p[0] = 0;
    swap(dp,p);

    int tx = -1;
    int ta = 0;
    if (t[now] == i) {
      tx = x[now];
      ta = a[now];
      now++;
    }

    REP(j,5) {
      if (p[j] == -1) continue;

      // 移動しない
      dp[j] = max(dp[j], p[j]);
      if (tx == j) dp[j] = max(dp[j], p[j]+ta);

      // -1
      if (j > 0) {
        if (tx == j) dp[j-1] = max(dp[j-1], p[j]+ta);
        else dp[j-1] = max(dp[j-1], p[j]);
      }
      // +1
      if (j < 4) {
        if (tx == j) dp[j+1] = max(dp[j+1], p[j]+ta);
        else dp[j+1] = max(dp[j+1], p[j]);
      }
    }
  }

  ll ans = 0;
  REP(i,5) ans = max(ans, dp[i]);
  cout << ans << endl;
  return 0;
}