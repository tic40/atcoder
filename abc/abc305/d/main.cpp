#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;

int main() {
  int n; cin >> n;
  vector<ll> a(n);
  REP(i,n) cin >> a[i];
  vector<ll> s(n); // 寝ていた時間の累積和
  for(int i = 2; i < n; i++) {
    s[i] += s[i-1];
    if (i % 2 == 0) s[i] += a[i] - a[i-1];
  }

  auto f = [&](ll x) -> ll {
    int i = lower_bound(a.begin(),a.end(),x) - a.begin() - 1;
    if (i < 0) return 0;
    ll res = s[i];
    if (i%2 == 1) res += x-a[i];
    return res;
  };

  int q; cin >> q;
  REP(_,q) {
    ll l,r; cin >> l >> r;
    ll ans = f(r) - f(l);
    cout << ans << endl;
  }
  return 0;
}