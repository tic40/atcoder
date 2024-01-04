#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using mint = modint998244353;

int main() {
  int n; cin >> n;

  mint a = (mint)1/2;
  vector<mint> pa(n+1,1);
  REP(i,n) pa[i+1] = pa[i]*a;

  // dp[i][j] := 列に i 人いるときに先頭から j 番目の人が最後に残る確率
  vector<mint> dp(1,1);
  for(int k = 2; k <= n; k++) {
    vector<mint> p(k);
    swap(dp,p);

    REP(i,k-1) dp[0] += pa[k-1-i]*p[i];
    REP(i,k-1) {
      mint now = dp[i];
      now -= p[i]*pa[k-1];
      now *= a;
      now += p[i];
      dp[i+1] = now;
    }
    mint x = (mint(2) - pa[k-1]).inv();
    REP(i,k) dp[i] *= x;
  }

  REP(i,n) cout << dp[i].val() << " ";
  return 0;
}