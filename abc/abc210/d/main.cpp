#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
using ll = long long;
const int INF = 1e9;
const ll LINF = 1e18;

ll h,w,c;
vector<vector<ll>> a;

void solve() {
  ll ans = LINF;

  REP(_, 2) {
    vector<vector<ll>> dp(h, vector<ll>(w, LINF));
    REP(i,h) REP(j,w) {
      if (i) dp[i][j] = min(dp[i][j], dp[i-1][j]);
      if (j) dp[i][j] = min(dp[i][j], dp[i][j-1]);
      ans = min(ans, a[i][j] + (i+j) * c + dp[i][j]);
      dp[i][j] = min(dp[i][j], a[i][j] - (i+j) * c);
    }
    reverse(a.begin(), a.end());
  }

  cout << ans << endl;
  return;
}

int main() {
  cin >> h >> w >> c;
  a.resize(h);
  REP(i,h) REP(j,w) {
    ll _; cin >> _;
    a[i].push_back(_);
  }

  solve();
  return 0;
}