#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using mint = modint998244353; // modint1000000007;

// Combination ライブラリ
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
  int a,b,c,d; cin >> a >> b >> c >> d;
  mint ans = 0;
  Combination comb(4e6+1);

  /*
    a > c
    a > d
    b > d

    [a,b混合][b,c混合][c,d混合]
  */
  REP(l,b+1) {
    mint now = comb(a-1+l,l);
    now *= comb((b-l+d)+c,c);
    ans += now;
  }
  cout << ans.val() << endl;
  return 0;
}