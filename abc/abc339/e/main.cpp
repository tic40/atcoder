#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int op(int a, int b) { return max(a,b); }
int e() { return 0; }

int main() {
  int n,d; cin >> n >> d;
  vector<int> a(n);
  REP(i,n) cin >> a[i];

  const int M = 500005;
  segtree<int,op,e> dp(M);

  REP(i,n) {
    int l = a[i]-d, r = a[i]+d+1;
    l = max(l,0);
    r = min(r,M);
    int now = dp.prod(l,r) + 1;
    dp.set(a[i],now);
  }

  int ans = dp.prod(0,M);
  cout << ans << endl;
  return 0;
}