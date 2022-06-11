#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
using ll = long long;

int main() {
  int n,q; cin >> n >> q;
  vector<int> a(n);
  REP(i,n) cin >> a[i];

  sort(a.begin(), a.end());
  vector<ll> m(n+1); // 累積和
  REP(i,n) m[i+1] = m[i]+a[i];

  REP(i,q) {
    ll x; cin >> x;
    auto it = upper_bound(a.begin(), a.end(), x);
    int idx = it - a.begin(); // xより大きい最も左側のindex

    ll d1 = m[idx] - m[0]; // x以下の部分の累積和
    ll ans = x * idx - d1;
    ll d2 = m[n] - m[idx]; // xより大きい部分の累積和
    ans += d2 - x * (n - idx);

    cout << ans << endl;
  }
  return 0;
}