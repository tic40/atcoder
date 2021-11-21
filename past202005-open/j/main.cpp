#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<(int)(n);i++)
using ll = long long;
const int INF = 1e9;
const ll LINF = 1e18;
const int MOD = 1e9+7;

int op(int a, int b) { return min(a, b); }
int e() { return INF; }

int main() {
  int n,m;
  cin >> n >> m;
  vector<int> a(m);

  segtree<int, op, e> seg(n);
  REP(i,n) seg.set(i,0);

  REP(i,m) {
    int a; cin >> a;
    int ok = n+1;
    int ng = 0;
    while(1 < (ok-ng)) {
      int mid = (ng+ok) / 2;
      if (seg.prod(0, mid) < a) ok = mid;
      else ng = mid;
    }
    if (ok < n+1) {
      seg.set(ok-1,a);
      cout << ok << endl;
    } else {
      cout << -1 << endl;
    }
  }
  return 0;
}