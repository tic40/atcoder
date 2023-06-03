#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'
using ll = long long;

int main() {
  int n,q; cin >> n >> q;
  vector<int> a(n);
  REP(i,n) cin >> a[i];
  vector<ll> e(n-1);
  REP(i,n-1) e[i] = a[i+1]-a[i];
  ll now = 0;
  REP(i,n-1) now += abs(e[i]);

  REP(_,q) {
    int l,r,v; cin >> l >> r >> v;
    l--; r--;
    ll before = 0, after = 0;
    if (r < n-1) {
      before += abs(e[r]);
      e[r] -= v;
      after += abs(e[r]);
    }
    if (l-1 >= 0) {
      before += abs(e[l-1]);
      e[l-1] += v;
      after += abs(e[l-1]);
    }
    now += after - before;
    cout << now << endl;
  }
  return 0;
}