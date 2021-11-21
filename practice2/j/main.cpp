#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<(int)(n);i++)
using ll = long long;
const int INF = 1e9;
const ll LINF = 1e18;
const int MOD = 1e9+7;

int op(int a, int b) { return max(a, b); }
int e() { return -1; }
int target;
bool f(int v) { return v < target; }

int main() {
  int n,q;
  cin >> n >> q;
  vector<int> a(n);
  REP(i,n) cin >> a[i];

  segtree<int, op, e> seg(a);

  REP(i,q) {
    int t; cin >> t;
    if (t == 1) {
      int x,v;
      cin >> x >> v;
      x--;
      seg.set(x,v);
    } else if (t == 2) {
      int l,r;
      cin >> l >> r;
      l--;
      cout << seg.prod(l,r) << endl;
    } else {
      int x;
      cin >> x >> target;
      x--;
      cout << seg.max_right<f>(x)+1 << endl;
    }

  }
  return 0;
}