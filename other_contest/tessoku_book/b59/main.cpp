#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;

int e() { return 0; }
int op(int a, int b) { return a+b; }

int main() {
  int n; cin >> n;
  vector<int> a(n);
  REP(i,n) {
    cin >> a[i];
    a[i]--;
  }

  segtree<int, op, e> seg(n);
  ll ans = 0;
  REP(i,n) {
    ans += seg.prod(a[i]+1,n);
    seg.set(a[i],1);
    cout << ans << endl;
  }
  cout << ans << endl;
  return 0;
}