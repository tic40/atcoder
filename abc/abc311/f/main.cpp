#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using mint = modint998244353;

int main() {
  int n,m; cin >> n >> m;
  vector<string> s(n);
  REP(i,n) cin >> s[i];

  // 初期状態を美しい状態になるように更新する
  REP(i,n) REP(j,m) {
    if (s[i][j] == '.') continue;
    if (i+1 < n) s[i+1][j] = '#';
    if (i+1 < n && j+1 < m) s[i+1][j+1] = '#';
  }

  // dp[i][j] = i 行目まで塗り方を決めて、
  // 美しいグリッドでありマス (i,j) を白く、マス (i,j+1) を黒く塗るようなものの個数
  vector dp(n+2,vector<mint>(m+1));
  dp[0][m] = 1;

  for(int j = m; j >= 0; j--) REP(i,n+2) {
    if (i+1 < n+2) dp[i+1][j] += dp[i][j];
    if (i-1 >= 0 && j-1 >= 0) {
      if (i == 1 || s[i-2][j-1] == '.') dp[i-1][j-1] += dp[i][j];
    }
  }

  cout << dp[n+1][0].val() << endl;
  return 0;
}