#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using P = pair<int,int>;

int op(int a, int b) { return min(a, b); }
int e() { return 1e9; }

int main() {
  int n,l,r; cin >> n >> l >> r;
  vector<int> x(n);
  REP(i,n) cin >> x[i];

  segtree<int, op, e> seg(n);
  seg.set(0,0);
  for(int i = 1; i < n; i++) {
    int posL = lower_bound(x.begin(), x.end(), x[i] - r) - x.begin();
    int posR = lower_bound(x.begin(), x.end(), x[i] - l + 1) - x.begin() - 1;
    int v = seg.prod(posL,posR+1) + 1;
    seg.set(i,v);
  }
  cout << seg.get(n-1) << endl;
  return 0;
}