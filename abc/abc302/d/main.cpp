#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;

int main() {
  ll n,m,d; cin >> n >> m >> d;
  vector<ll> a(n),b(m);
  REP(i,n) cin >> a[i];
  REP(i,m) cin >> b[i];
  sort(b.begin(),b.end());

  ll ans = -1;
  REP(i,n) {
    ll now = a[i];
    int idx = upper_bound(b.begin(),b.end(),d+now) - b.begin() - 1;
    if (idx < 0) continue;
    if (abs(now-b[idx]) <= d) ans = max(ans, now+b[idx]);
  }
  cout << ans << endl;
  return 0;
}