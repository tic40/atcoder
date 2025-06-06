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
  int a,b,c,d; cin >> a >> b >> c >> d;
  Combination comb(4e6+1);
  mint ans = 0;

  /*
    a > c
    a > d
    b > d
    左から以下の順序になる
    [a or b][b or c][c or d]
    l := [a or b] の部分に置く b の個数
  */
  REP(l,b+1) {
    // a-1+l個の要素から l個選ぶ組み合わせ
    // これは左端のaとbの並び方を表す
    // -1 しているのは、[a or b] の部分の右端は必ず A になるからその分を -1
    mint now = comb(a-1+l,l);

    // (b-l+d)+c個の要素から c個選ぶ組み合わせ
    // これは残りのb,c,dの並び方を表す
    // b-l: 残りのbの個数
    // d: dの個数
    // c: cの個数
    now *= comb((b-l)+d+c,c);

    // 全ての組み合わせを足し合わせる
    ans += now;
  }
  cout << ans.val() << endl;
  return 0;
}