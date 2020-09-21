#include <bits/stdc++.h>
using namespace std;
#define COUT(x) cout<<(x)<<"\n"
#define REP(i, n) for(int i=0;i<n;i++)
#define endl "\n"
using ll = long long;
const int MOD = 998244353;

int main() {
  int n,k; cin >> n >> k;
  vector<int> l(k),r(k);
  REP(i,k) cin >> l[i] >> r[i];
  vector<ll> dp(n+1), dpsum(n+1);

  dp[1] = 1; // マス1から始まるため dp[1] = 1 にする
  dpsum[1] = 1; // dpの累積和

  for (int i = 2; i <= n; i++) {
    REP(j,k) {
      int li = max(i-r[j], 1);
      int ri = i-l[j];
      if (ri < 0) continue; // 右端が範囲外

      dp[i] += dpsum[ri]-dpsum[li-1];
      dp[i] = dp[i] < 0 ? dp[i]+MOD : dp[i]%MOD; // MOD
    }
    dpsum[i] = (dpsum[i-1]+dp[i]) % MOD;
  }

  COUT(dp[n]);
  return 0;
}