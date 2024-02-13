#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;

using S = ll;
using F = ll;
// S op(S a, S b){ return a+b; }
S op(S a, S b){ return 0; }
S e(){ return 0; }
S mapping(F f, S x){ return f+x; }
F composition(F f, F g){ return f+g; }
F id(){ return 0; }

int main() {
  int n,m; cin >> n >> m;
  vector<int> a(n),b(m);
  REP(i,n) cin >> a[i];
  REP(i,m) cin >> b[i];

  // fenwick tree 累積和
  auto solve1 = [&]() {
    fenwick_tree<ll> fw(n+1); // 累積和
    REP(i,n) {
      fw.add(i,a[i]);
      fw.add(i+1,-a[i]);
    }
    REP(i,m) {
      ll now = fw.sum(0,b[i]+1);
      ll r = now / n; // 何周するか
      ll rem = now % n; // r周した余り分

      fw.add(b[i],-now);
      fw.add(b[i]+1,now);
      fw.add(0,r);

      if (b[i]+rem < n) {
        fw.add(b[i]+1,1);
        fw.add(b[i]+rem+1,-1);
      } else {
        fw.add(b[i]+1,1);
        fw.add(0,1);
        fw.add((rem+b[i])%n+1, -1);
      }
    }
    REP(i,n) cout << fw.sum(0,i+1) << " ";
  };

  // lazy segtree
  auto solve2 = [&]() {
    lazy_segtree<S,op,e,F,mapping,composition,id> seg(n+1);
    REP(i,n) seg.set(i,a[i]);
    REP(i,m) {
      ll now = seg.get(b[i]);
      ll r = now / n;
      ll rem = now % n;
      seg.set(b[i],0);
      seg.apply(0,n,r);

      if (b[i]+rem < n) {
        seg.apply(b[i]+1, b[i]+rem+1,1);
      } else {
        seg.apply(b[i]+1,n,1);
        seg.apply(0, (b[i]+rem) % n + 1,1);
      }
    }

    REP(i,n) cout << seg.get(i) << " ";
  };

  solve1();
  // solve2();
  return 0;
}