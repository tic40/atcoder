#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'
using mint = modint998244353;

int main() {
  int n, p; cin >> n >> p;
  mint x1 = (mint)p / 100;
  mint x2 = (mint)1 - x1;

  // dp[i] := 体力がi以下になるときの期待値
  vector<mint> dp(n+2);
  for(int i = n-1; i >= 0; i--) {
    dp[i] += (dp[i+2] + 1) * x1;
    dp[i] += (dp[i+1] + 1) * x2;
  }

  cout << dp[0].val() << endl;
  return 0;
}