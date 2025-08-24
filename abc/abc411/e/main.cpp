#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using P = pair<int,int>;
using mint = modint998244353;

mint op(mint a, mint b) { return a*b; }
mint e() { return mint(1); }

int main() {
  int n; cin >> n;
  const int m = 6;
  vector<P> pa;
  REP(i,n) REP(j,m) {
    int a; cin >> a;
    pa.emplace_back(a,i);
  }
  sort(pa.begin(),pa.end());
  const mint inv6 = mint(6).inv();

  segtree<mint,op,e> seg(vector<mint>(n,mint(0)));
  mint ans = 0;
  for(auto [a,i]: pa) {
    ans += a * inv6 * seg.prod(0,i) * seg.prod(i+1,n);
    seg.set(i, seg.get(i)+inv6);
  }
  cout << ans.val() << endl;
  return 0;
}