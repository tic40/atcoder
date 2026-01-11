#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;

int main() {
  int n; ll x,y; cin >> n >> x >> y;
  vector<ll> a(n);
  REP(i,n) cin >> a[i];
  sort(a.begin(),a.end());

  ll w = a[0] * y;
  ll ans = 0;
  REP(i,n) {
    ll sw = a[i] * y; // y だけを配った場合
    ll dif = sw - w;
    if (dif % (y-x) != 0) { cout << -1 << endl; return 0; }

    ll num = dif / (y-x); // num 個だけ x(小さい飴)を選ぶ必要がある
    if (num > a[i]) { cout << -1 << endl; return 0; }

    ans += a[i] - num;
  }
  cout << ans << endl;
  return 0;
}
