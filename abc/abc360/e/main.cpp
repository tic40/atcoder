#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using mint = modint998244353; // modint1000000007;

int main() {
  int n,k; cin >> n >> k;
  // p: 黒いボールが最も左にある状態から 1 回操作して、黒いボールが最も左以外のどこかに移動する確率
  // q: 黒いボールが最も左以外のどこかにある状態から 1 回操作して、黒いボールが最も左に移動する確率
  // dp[i] := i 回後に黒いボールが最も左にある確率
  mint p = mint(2) * (n-1) / n / n;
  mint q = mint(2) / n / n;
  vector<mint> dp(k+1);
  dp[0] = 1;
  REP(i,k) {
    // 黒いボールが最も左から動かないケース
    dp[i+1] += (mint(1) - p) * dp[i];
    // 黒いボールが最も左以外のどこかから、最も左へ移動するケース
    dp[i+1] += q * (mint(1) - dp[i]);
  }
  mint ans = dp[k] + (mint(1) - dp[k]) * (mint(2+n) / 2);
  cout << ans.val() << endl;
  return 0;
}