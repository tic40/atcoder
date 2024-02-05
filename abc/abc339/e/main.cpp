#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

using S = ll;
using F = ll;
S op(S a, S b){ return max(a, b); }
S e(){ return 0; }
S mapping(F f, S x){ return f+x; }
F composition(F f, F g){ return f+g; }
F id(){ return 0; }

int main() {
  int n,d; cin >> n >> d;
  vector<int> a(n);
  REP(i,n) cin >> a[i];

  const int M = 500005;
  // dp[i][j] := i 個目までみて最後に選んだのが値 j のときの max
  // segtree で解ける。練習で lazy segtree を使ってみたただけ
  // segtree<int,op,e> seg(M);
  lazy_segtree<S, op, e, F, mapping, composition, id> seg(M);

  REP(i,n) {
    int l = max(0, a[i]-d);
    int r = min(M, a[i]+d+1);
    int now = seg.prod(l,r) + 1;
    seg.set(a[i],now);
  }

  int ans = seg.prod(0,M);
  cout << ans << endl;
  return 0;
}