#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
using ll = long long;
const int INF = 1e9+5;

int main() {
  int n,W; cin >> n >> W;
  vector<int> w(n),v(n);
  REP(i,n) cin >> w[i] >> v[i];

  vector<ll> dp(1e5+1, INF); // [価値] = 重さ
  dp[0] = 0;
  REP(i,n) {
    vector<ll> p(1e5+1, INF);
    REP(now, 1e5+1) {
      p[now] = min(p[now], dp[now]);
      if ( W < dp[now] + w[i] ) continue;
      p[now + v[i]] = min(p[now + v[i]], dp[now] + w[i]);
    }
    swap(dp,p);
  }

  int ans = 0;
  for(int i = 1e5; 0 <= i; i--) if (dp[i] <= W) { ans = i; break; }
  cout << ans << endl;
  return 0;
}