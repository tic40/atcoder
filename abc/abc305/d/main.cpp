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

  int q; cin >> q;
  REP(_,q) {
    ll l,r; cin >> l >> r;
    auto idxl = lower_bound(a.begin(),a.end(),l) - a.begin();
    auto idxr = upper_bound(a.begin(),a.end(),r) - a.begin() - 1;
    ll ans = s[idxr] - s[idxl];
    if (idxl % 2 == 0) ans += a[idxl] - l;
    if (idxr % 2 == 1) ans += r - a[idxr];
    cout << ans << endl;
  }
  return 0;
}