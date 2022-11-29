#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'
using mint = modint1000000007;

int main() {
  int n; string s;
  cin >> n >> s;

  // dp[i][j] = i番目まで決めたとき、
  // i番目の数より大きいものがj個残っているような場合の数
  vector dp(n+1,vector<mint>(n+1));
  vector<mint> cum(n+1);
  REP(i,n) dp[1][i] = 1;

  for(int i = 1; i < n; i++) {
    REP(j,n) cum[j+1] = cum[j] + dp[i][j];

    if (s[i-1] == '<') {
      REP(j,n) dp[i+1][j] = cum[n-i+1]-cum[j+1];
    } else {
      REP(j,n) dp[i+1][j] = cum[j+1];
    }
  }

  cout << dp[n][0].val() << endl;
  return 0;
}