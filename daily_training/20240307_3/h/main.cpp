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
  int n,m,k; cin >> n >> m >> k;
  vector<int> deg(n);
  REP(i,m) {
    int u,v; cin >> u >> v;
    u--; v--;
    deg[u] ^= 1;
    deg[v] ^= 1;
  }
  int one = 0, zero = 0;
  REP(i,n) deg[i] == 1 ? one++ : zero++;

  Combination c(2e5+1);
  mint ans = 0;
  // 次数が奇数個の頂点は偶数個選ぶ * 次数が偶数個の頂点は何個選んでもok
  for(int i = 0; i <= k; i+=2) ans += c(one,i) * c(zero,k-i);
  cout << ans.val() << endl;
  return 0;
}