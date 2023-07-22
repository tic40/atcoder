#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;

int main() {
  int h,w,n; cin >> h >> w >> n;
  vector g(h,vector<bool>(w));
  REP(i,n) {
    int a,b; cin >> a >> b;
    a--; b--;
    g[a][b] = true;
  }

  // dp[i][j] := i,j マスまでで、i,j を含んで作れる穴のない正方形の総数
  vector dp(h,vector<ll>(w));
  REP(i,h) REP(j,w) {
    if (g[i][j]) continue;
    dp[i][j] = 1;
    if (i-1 >= 0 && j-1 >= 0) dp[i][j] += min({ dp[i-1][j-1], dp[i-1][j], dp[i][j-1] });
  }

  ll ans = 0;
  REP(i,h) REP(j,w) ans += dp[i][j];
  cout << ans << endl;
  return 0;
}