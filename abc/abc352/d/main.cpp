#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
const int INF = numeric_limits<int>::max();

int op1(int a, int b) { return max(a, b); }
int e1() { return 0; }
int op2(int a, int b) { return min(a, b); }
int e2() { return INF; }

int main() {
  int n,k; cin >> n >> k;
  segtree<int, op1, e1> seg_max(n);
  segtree<int, op2, e2> seg_min(n);
  REP(i,n) {
    int p; cin >> p; p--;
    seg_max.set(p,i);
    seg_min.set(p,i);
  }

  int ans = INF;
  REP(i,n-k+1) {
    int l = i, r = i+k-1;
    int mx = seg_max.prod(l,r+1);
    int mi = seg_min.prod(l,r+1);
    ans = min(ans,mx-mi);
  }
  cout << ans << endl;
  return 0;
}