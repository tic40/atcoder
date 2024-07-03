#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using mint = modint998244353; // modint1000000007;

int main() {
  int n,k; cin >> n >> k;

  auto solve1 = [&]() {
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
  };

  auto solve2 = [&]() {
    // dp[i][0] := i 個までみたとき、黒いボールが最も左にある状態の確率
    // dp[i][1] := i 個までみたとき、黒いボールが最も左以外にある状態の確率
    vector dp(k+1, vector<mint>(2));
    dp[0][0] = 1;
    const mint invn = mint(n).inv();

    REP(i,k) {
      dp[i+1][0] += dp[i][0]*(1+mint(n-1)*(n-1))*invn*invn;
      dp[i+1][0] += dp[i][1]*2*(n-1)*invn*invn;
      dp[i+1][1] += dp[i][0]*2*invn*invn;
      dp[i+1][1] += dp[i][1]*(mint(n)*n-2)*invn*invn;
    }
    cout << (dp[k][0] + dp[k][1] * (mint(n)*(n+1)/2-1)).val() << endl;
  };

  solve2();
  return 0;
}