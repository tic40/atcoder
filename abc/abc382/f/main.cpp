#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using T = tuple<int,int,int>;
const int INF = numeric_limits<int>::max();

using S = int;
using F = int;
S op(S a, S b) { return min(a,b); }
S e() { return INF; }
S mapping(F f, S x) { return min(x,f); }
F composition(F f, F g) { return min(f,g); }
F id() { return INF; }

int main() {
  int h,w,n; cin >> h >> w >> n;
  vector bars(h,vector<T>());
  REP(i,n) {
    int r,c,l; cin >> r >> c >> l; r--; c--;
    bars[r].emplace_back(c,l,i);
  }

  lazy_segtree<S, op, e, F, mapping, composition, id> seg(w);
  seg.apply(0,w,h-1);
  vector<int> ans(n);
  for(int r = h-1; r >= 0; r--) {
    for(auto [c,l,id]: bars[r]) {
      int now = seg.prod(c,c+l);
      ans[id] = now;
      seg.apply(c,c+l,now-1);
    }
  }

  REP(i,n) cout << ans[i]+1 << endl;
  return 0;
}