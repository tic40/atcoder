#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;
 using mint = modint998244353;

struct modinv {
  int n; vector<mint> d;
  modinv(): n(2), d({0,1}) {}
  mint operator()(int i) {
    while (n <= i) d.push_back(-d[mint::mod()%n]*(mint::mod()/n)), ++n;
    return d[i];
  }
  mint operator[](int i) const { return d[i];}
} invs;
struct modfact {
  int n; vector<mint> d;
  modfact(): n(2), d({1,1}) {}
  mint operator()(int i) {
    while (n <= i) d.push_back(d.back()*n), ++n;
    return d[i];
  }
  mint operator[](int i) const { return d[i];}
} facts;
struct modfactinv {
  int n; vector<mint> d;
  modfactinv(): n(2), d({1,1}) {}
  mint operator()(int i) {
    while (n <= i) d.push_back(d.back()*invs(n)), ++n;
    return d[i];
  }
  mint operator[](int i) const { return d[i];}
} ifacts;
mint comb(int n, int k) {
  if (n < k || k < 0) return 0;
  return facts(n)*ifacts(k)*ifacts(n-k);
}

int main() {
  int h,w,k; cin >> h >> w >> k;
  mint ans;

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