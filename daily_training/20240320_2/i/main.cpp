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
  int h,w,k; cin >> h >> w >> k;
  Combination c(h*w);
  mint ans = 0;
  REP(i,h+1) REP(j,w+1) {
    mint now = 0;
    REP(s,1<<4) {
      int ni = i, nj = j;
      if ((s >> 0)&1) ni--;
      if ((s >> 1)&1) ni--;
      if ((s >> 2)&1) nj--;
      if ((s >> 3)&1) nj--;
      if (ni < 0 || nj < 0) continue;
      int sg = (__builtin_parity(s)) ? -1 : 1;
      now += c(ni*nj,k) * sg;
    }
    ans += now * i * j * (h-i+1) * (w-j+1);
  }
  ans = ans / c(h*w,k);
  cout << ans.val() << endl;
  return 0;
}