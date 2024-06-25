#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;
const int INF = numeric_limits<int>::max();
const ll LINF = numeric_limits<ll>::max();
void chmin(ll& a, ll b) { a = min(a,b); }

int main() {
  int n,W; cin >> n >> W;
  vector<int> w(n),v(n);
  REP(i,n) cin >> w[i] >> v[i];

  // dp[i][j] := i 個までみたとき、価値が j のときの最小の重さ
  vector dp(n+1, vector<ll>(1e5+1, LINF));
  dp[0][0] = 0;

  REP(i,n) {
    REP(j,1e5+1) if (dp[i][j] != LINF) {
      chmin(dp[i+1][j], dp[i][j]);
      int nj = j + v[i];
      chmin(dp[i+1][nj], dp[i][j]+w[i]);
    }
  }

  ll ans = 0;
  REP(i,1e5+1) if (dp[n][i] <= W) ans = i;
  cout << ans << endl;
  return 0;
}