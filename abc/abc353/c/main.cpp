#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;

int main() {
  int n; cin >> n;
  vector<int> a(n);
  REP(i,n) cin >> a[i];
  sort(a.begin(),a.end());
  vector<ll> s(n+1);
  REP(i,n) s[i+1] = s[i] + a[i];

  ll ans = 0;
  REP(i,n-1) {
    ll now = (ll)a[i] * (n-1-i) + s[n] - s[i+1];

    int idx = lower_bound(a.begin(),a.end(),1e8 - a[i]) - a.begin();
    if (idx <= i) idx = i+1;
    now -= (ll)1e8 * (max(0, n - idx));
    ans += now;
  }
  cout << ans << endl;
  return 0;
}