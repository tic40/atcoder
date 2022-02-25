#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<(int)(n);i++)
using ll = long long;
const int INF = 1e9;
const ll LINF = 1e18;

int n,k;
vector<int> x,y;

ll dist(int i, int j) {
  return (ll)(x[i]-x[j])*(x[i]-x[j]) + (ll)(y[i]-y[j])*(y[i]-y[j]);
}

void solve() {
  vector<vector<ll>> d(n, vector<ll>(n));
  // 全点間の距離を前計算
  REP(i,n) REP(j,n) d[i][j] = dist(i,j);

  // グループに含まれる集合がbitのときの2点間距離の最大値
  vector<ll> cost(1<<n);
  REP(bit,1<<n) {
    REP(i,n) REP(j,i) {
      if ( ((bit >> i) & 1) && ((bit >> j) & 1) ) {
        cost[bit] = max(cost[bit], d[i][j]);
      }
    }
  }

  // dp[i][j] : dp[すでに選んだ点のbit][何個のグループ数に分けたときか]
  vector<vector<ll>> dp(1<<n, vector<ll>(k+1, LINF));
  dp[0][0] = 0;
  REP(bit, 1<<n) {
    for(int i = 1; i <= k; i++) {
      for(int j = bit; j > 0; j = (j-1) & bit) {
        dp[bit][i] = min(dp[bit][i], max(dp[bit-j][i-1], cost[j]));
      }
    }
  }

  cout << dp[(1<<n)-1][k] << endl;
  return;
}

int main() {
  cin >> n >> k;
  x.resize(n);
  y.resize(n);
  REP(i,n) cin >> x[i] >> y[i];

  solve();
  return 0;
}