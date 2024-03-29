#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using mint = modint1000000007;

int main() {
  int k; cin >> k;
  // x の各桁の和が 9 の倍数であれば x は 9 の倍数
  if (k % 9) { cout << 0 << endl; return 0; }

  // dp[i] := 各桁の和が i のときに何通りあるか
  vector<mint> dp(k+1);
  dp[0] = 1;
  REP(i,k+1) for(int j = 1; j <= 9; j++) {
    if (i - j >= 0) dp[i] += dp[i-j];
  }
  cout << dp[k].val() << endl;
  return 0;
}