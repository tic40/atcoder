#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
using ll = long long;
const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;

int dp[400][400];
int n,m;

void solve() {
  ll ans = 0;
  REP(k,n) { // 経由する頂点
    REP(i,n) { // 開始頂点
      REP(j,n) { // 終端
        dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
        if (dp[i][j] != INF) ans += dp[i][j];
      }
    }
  }

  cout << ans << endl;
  return;
}

int main() {
  cin >> n >> m;
  REP(i,n) REP(j,n) dp[i][j] = INF;
  REP(i,n) dp[i][i] = 0;

  REP(i,m) {
    int a,b,c;
    cin >> a >> b >> c;
    dp[a-1][b-1] = c;
  }

  solve();
  return 0;
}