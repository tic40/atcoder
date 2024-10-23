#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using mint = modint1000000007;

int main() {
  string s; cin >> s;
  int n = s.size();
  // dp[i][j] := i 桁目で、j=0: i 桁目まで一致, j=1: 未満
  vector dp(n+1,vector<mint>(2));
  dp[0][0]=1;
  REP(i,n) {
    { // a+b = 0 にするとき
      if (s[i] == '0') {
        dp[i+1][0] += dp[i][0];
        dp[i+1][1] += dp[i][1];
      } else {
        // s[i] = 1 で a+b = 0 にするときは未満になるので j=1 にだけ遷移
        dp[i+1][1] += dp[i][0];
        dp[i+1][1] += dp[i][1];
      }
    }
    { // a+b = 1
      if (s[i] == '0') {
        // s[i] = 0 で a+b = 1 にするときは未満になるので j=1 にだけ遷移
        // a+b = 1 は a=1,b=0 と a=0,b=1 と二通りあるため * 2
        dp[i+1][1] += dp[i][1]*2;
      } else {
        dp[i+1][0] += dp[i][0]*2;
        dp[i+1][1] += dp[i][1]*2;
      }
    }
  }

  cout << (dp[n][0] + dp[n][1]).val() << endl;
  return 0;
}