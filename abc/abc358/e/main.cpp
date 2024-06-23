#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;
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
  const int n = 26;
  int k; cin >> k;
  vector<int> c(n);
  REP(i,n) cin >> c[i];

  Combination comb(1000);
  vector dp(n+1,vector<mint>(k+1));
  dp[0][0] = 1;
  REP(i,n) {
    REP(j,k+1) REP(a,c[i]+1) {
      int nj = j + a;
      if (nj > k) break;
      dp[i+1][nj] += dp[i][j] * comb(nj,a);
    }
  }

  mint ans = 0;
  for(int i = 1; i <= k; i++) ans += dp[n][i];
  cout << ans.val() << endl;
  return 0;
}
