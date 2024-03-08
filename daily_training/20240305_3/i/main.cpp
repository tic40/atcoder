#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using mint = modint998244353; // modint1000000007;

struct Combination {
  vector<mint> fact, ifact;
  Combination(int n):fact(n+1),ifact(n+1) {
    fact[0] = 1;
    for (int i = 1; i <= n; ++i) fact[i] = fact[i-1]*i;
    ifact[n] = fact[n].inv();
    for (int i = n; i >= 1; --i) ifact[i-1] = ifact[i]*i;
  }
  mint operator()(int n, int k) {
    if (k < 0 || k > n) return 0;
    return fact[n]*ifact[k]*ifact[n-k];
  }
};

int main() {
  int n,m; cin >> n >> m;
  int n2 = n*2;
  vector g(n2,vector<int>(n2));
  REP(i,m) {
    int a,b; cin >> a >> b;
    a--; b--;
    g[a][b] = g[b][a] = 1;
  }
  // dp[l][r] := l,r を取る操作が何通りあるか
  vector dp(n2,vector<mint>(n2+1));
  REP(i,n2) dp[i][i] = 1;
  Combination c(205);

  for(int len = 2; len <= n2; len+=2) {
    REP(l,n2) {
      int r = l+len;
      if (r > n2) break;
      for (int i = l; i < r; i += 2) {
        if (g[i][r-1] == 0) continue; // 仲が悪い場合
        // ペアの選び方の順序は自由に決められるので combination を掛ける
        dp[l][r] += dp[l][i] * dp[i+1][r-1] * c((r-l)/2, (i-l)/2);
      }
    }
  }
  cout << dp[0][n2].val() << endl;
  return 0;
}