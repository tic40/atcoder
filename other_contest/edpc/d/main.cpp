#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
using ll = long long;

int main() {
  int n,W; cin >> n >> W;
  vector<int>  w(n),v(n);
  REP(i,n) cin >> w[i] >> v[i];

  vector<ll> dp(W+1); // [重さ] = 最大の価値
  REP(i,n) {
    vector<ll> p(W+1);
    REP(now,W+1) {
      p[now] = max(p[now], dp[now]);
      if (W < now + w[i]) continue;
      p[ now + w[i] ] = max( p[ now + w[i] ], dp[now] + v[i] );
    }
    swap(dp,p);
  }

  ll ans = 0;
  REP(i,W+1) ans = max(ans, dp[i]);
  cout << ans << endl;
  return 0;
}
