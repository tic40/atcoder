#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;

const int p1 = 1000000021;
const int p2 = 1000000021;
struct mints {
  int d1, d2;
  mints(int val=0): d1(val), d2(val) {}
  mints(int d1, int d2): d1(d1), d2(d2) {}
  mints operator+(const mints& a) const {
    return mints((d1+a.d1)%p1, (d2+a.d2)%p2);
  }
  mints operator*(const mints& a) const {
    return mints(((ll)d1*a.d1)%p1, ((ll)d2*a.d2)%p2);
  }
  bool operator==(const mints& a) const {
    return d1 == a.d1 && d2 == a.d2;
  }
};

struct D {
  mints h, c;
  D() {}
  D(mints h, mints c): h(h), c(c) {}
};
D op(D a, D b) {
  return D(a.h+b.h*a.c, a.c*b.c);
}
D e() { return D(0,1);}

int main() {
  int n, q; string s;
  cin >> n >> q >> s;

  int x = rand()%p1;
  segtree<D,op,e> t1(n), t2(n);
  REP(i,n) t1.set(i, D(s[i],x));
  REP(i,n) t2.set(n-1-i, D(s[i],x));

  REP(qi,q) {
    int t; cin >> t;

    if (t == 1) {
      int i; char c; cin >> i >> c;
      i--;
      t1.set(i, D(c,x));
      t2.set(n-1-i, D(c,x));
    } else {
      int l, r; cin >> l >> r;
      l--;
      mints h1 = t1.prod(l,r).h;
      mints h2 = t2.prod(n-r,n-l).h;
      cout << (h1 == h2 ? "Yes" : "No") << endl;
    }
  }
  return 0;
}