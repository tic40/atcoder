#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;
using P = pair<int,int>;
template<class T> void chmax(T& a, T b) { a = max(a,b); }

int main() {
  int n; cin >> n;
  vector<int> t(n),x(n),a(n);
  REP(i,n) cin >> t[i] >> x[i] >> a[i];
  vector<P> e(1e5+1);
  REP(i,n) e[t[i]] = {x[i],a[i]};

  // dp[i][j] 時刻 i に座標 j にいるときの合計の最大値
  int tm = 100000;
  int xm = 4;
  vector dp(tm+2, vector<ll>(xm+2, -1));
  dp[0][0] = 0;

  for(int i = 1; i <= tm; i++) {
    auto [nx,na] = e[i];
    REP(x,xm+1) {
      int add = (x == nx) ? na : 0;
      if (x > 0 && dp[i-1][x-1] != -1) chmax(dp[i][x], dp[i-1][x-1] + add);
      if (dp[i-1][x] != -1) chmax(dp[i][x], dp[i-1][x] + add);
      if (x < 4 && dp[i-1][x+1] != -1) chmax(dp[i][x], dp[i-1][x+1] + add);
    }
  }

  ll ans = 0;
  REP(i,xm+1) chmax(ans,dp[tm][i]);
  cout << ans << endl;
  return 0;
}