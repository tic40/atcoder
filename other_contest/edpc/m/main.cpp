#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
using mint = modint1000000007;

int main() {
  int n,k; cin >> n >> k;
  vector<int> a(n);
  REP(i,n) cin >> a[i];

  // dp[i][j] = i個目までみたときに、 k 飴を分ける方法が何通りあるか
  vector dp(n+1, vector<mint>(k+1));
  dp[0][0] = 1;
  REP(i,n) {
    // 累積和
    vector<mint> s(k+2);
    REP(j,k+1) s[j+1] = s[j] + dp[i][j];
    // 貰うDP
    REP(j,k+1) dp[i+1][j] = s[j+1] - s[max(0,j-a[i])];
  }

  cout << dp[n][k].val() << endl;
  return 0;
}