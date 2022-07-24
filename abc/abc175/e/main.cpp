#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'
using ll = long long;

template<typename T>
void chmax(T& a, const T& b) { a = max(a,b); }

ll dp[3005][3005][4];

int main() {
  int r,c,k; cin >> r >> c >> k;
  vector g(r+1, vector<int>(c+1));
  REP(i,k) {
    int a,b,v; cin >> a >> b >> v;
    g[a][b] = v;
  }

  for(int i = 1; i <= r; i++) for(int j = 1; j <= c; j++) {
    // アイテムを取らない
    REP(t,4) {
      chmax(dp[i][j][0], dp[i-1][j][t]);
      chmax(dp[i][j][t], dp[i][j-1][t]);
    }

    // アイテムがあったら取る
    if (g[i][j] > 0) {
      REP(t,4) chmax(dp[i][j][1], dp[i-1][j][t] + g[i][j]);
      REP(t,3) chmax(dp[i][j][t+1], dp[i][j-1][t] + g[i][j]);
    }
  }

  ll ans = 0;
  REP(i,4) chmax(ans, dp[r][c][i]);
  cout << ans << endl;
  return 0;
}