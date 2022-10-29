#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'
using mint = modint998244353;

int main() {
  int n,m,k; cin >> n >> m >> k;

  mint m_inv = mint(1) / m;
  vector<mint> dp(n+1);
  dp[0] = 1;
  REP(i,k) {
    vector<mint> p(n+1);
    swap(dp,p);
    dp[n] = p[n];
    for(int j = 1; j <= m; j++) {
      REP(l,n) {
        if (p[l] == 0) continue;
        int nl = l+j;
        if (nl > n) nl = n-(nl-n);
        dp[nl] += p[l] * m_inv;
      }
    }
  }

  cout << dp[n].val() << endl;
  return 0;
}