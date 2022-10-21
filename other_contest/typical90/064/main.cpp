#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'
using ll = long long;

int main() {
  int n,q; cin >> n >> q;
  vector<int> a(n);
  REP(i,n) cin >> a[i];

  vector<ll> e(n);
  REP(i,n-1) e[i] = a[i+1]-a[i];
  ll ans = 0;
  REP(i,n-1) ans += abs(e[i]);

  REP(_,q) {
    int l,r,v; cin >> l >> r >> v;
    l--; r--;

    ll before = abs(e[r]);
    if (l-1 >= 0) before += abs(e[l-1]);

    if (l-1 >= 0) e[l-1] += v;
    if (r < n-1) e[r] -= v;

    ll after = abs(e[r]);
    if (l-1 >= 0) after += abs(e[l-1]);

    ans += after - before;
    cout << ans << endl;
  }
  return 0;
}