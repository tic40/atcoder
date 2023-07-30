#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using mint = modint998244353;

int main() {
  string s; cin >> s;
  int n = s.size();

  // dp[i][j] := i 文字目まで決めたとき、'(' と ')' の数の差が j のときの場合の数
  vector dp(n+1,vector<mint>(n+1));
  dp[0][0] = 1;
  REP(i,n) REP(j,i+1) {
    if (s[i] == '(' || s[i] == '?') dp[i+1][j+1] += dp[i][j];
    if (s[i] == ')' || s[i] == '?') {
      if (j-1 >= 0) dp[i+1][j-1] += dp[i][j];
    }
  }
  cout << dp[n][0].val() << endl;
  return 0;
}