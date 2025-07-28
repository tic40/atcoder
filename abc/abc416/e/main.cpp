#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;
const ll LINF = 1e18;
template<class T> void chmin(T& a, T b) { a = min(a,b); }

int main() {
  int n,m; cin >> n >> m;
  n++;
  vector dp(n,vector<ll>(n,LINF));
  REP(i,n) dp[i][i] = 0;
  REP(i,m) {
    int a,b; ll c; cin >> a >> b >> c; a--; b--;
    chmin(dp[a][b],c);
    chmin(dp[b][a],c);
  }

  int k,t; cin >> k >> t;
  REP(i,k) {
    int d; cin >> d; d--;
    dp[d][n-1] = t;
    dp[n-1][d] = 0;
  }

  REP(k,n) REP(i,n) REP(j,n) chmin(dp[i][j], dp[i][k]+dp[k][j]);
  int q; cin >> q;
  REP(_,q) {
    int type; cin >> type;
    if (type == 1) {
      int x,y; ll t; cin >> x >> y >> t;
      x--; y--;
      chmin(dp[x][y],t);
      chmin(dp[y][x],t);
      REP(i,n) REP(j,n) {
        chmin(dp[i][j],dp[i][x]+dp[x][y]+dp[y][j]);
        chmin(dp[i][j],dp[i][y]+dp[y][x]+dp[x][j]);
      }
    }
    if (type == 2) {
      int x; cin >> x; x--;
      dp[x][n-1] = t;
      dp[n-1][x] = 0;
      REP(i,n) REP(j,n) {
        chmin(dp[i][j],dp[i][x]+dp[x][n-1]+dp[n-1][j]);
        chmin(dp[i][j],dp[i][n-1]+dp[n-1][x]+dp[x][j]);
      }
    }
    if (type == 3) {
      ll now = 0;
      REP(i,n-1) REP(j,n-1) if (dp[i][j] != LINF) {
        now += dp[i][j];
      }
      cout << now << endl;
    }
  }
  return 0;
}