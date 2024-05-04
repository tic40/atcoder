#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;
 using mint = modint998244353;

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
  mint ans;
  Combination comb(h*w);

  for(int r = 1; r <= h; r++) {
    for(int c = 1; c <= w; c++) {
      mint now;
      REP(s,1<<4) {
        int nr = r, nc = c;
        if (s&1) nr--;
        if (s&2) nr--;
        if (s&4) nc--;
        if (s&8) nc--;
        if (nr < 0 || nc < 0) continue;
        int sg = (__builtin_parity(s)) ? -1 : 1;
        now += comb(nr * nc, k) * sg;
      }
      // 場合の数 x 面積 x これ以降の場合の数
      ans += now * r * c * (h-r+1) * (w-c+1);
    }
  }
  ans /= comb(h*w,k);
  cout << ans.val() << endl;
  return 0;
}