#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
const int INF = numeric_limits<int>::max();
int op(int a, int b) { return min(a,b); }
int e() { return INF; }

int main() {
  int n; cin >> n;
  vector<int> c(n),a(n);
  REP(i,n-1) cin >> c[i+1];
  REP(i,n-1) cin >> a[i+1];

  auto solve = [](vector<int>& c) {
    int n = c.size();
    segtree<int,op,e> seg(n+1);
    seg.set(0,0);
    REP(i,n) {
      int ni = i+1;
      int l = max(0,ni-c[i]);
      int r = ni;
      seg.set(ni,seg.prod(l,r)+1);
    }
    return seg.get(n);
  };

  int ans = 0;
  vector<int> nc;
  for(int i = 1; i < n; i++) {
    nc.push_back(c[i]);
    if (a[i] > 0) {
      ans += solve(nc);
      nc.clear();
    }
  }
  cout << ans << endl;
  return 0;
}