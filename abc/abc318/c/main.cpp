#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;
const ll LINF = numeric_limits<ll>::max();

int main() {
  ll n,d,p; cin >> n >> d >> p;
  vector<ll> f(n);
  REP(i,n) cin >> f[i];

  sort(f.rbegin(),f.rend());
  vector<ll> s(n+1);
  REP(i,n) s[i+1] = s[i]+f[i];

  ll ans = LINF;
  for(int i = 0; i <= n/d+1; i++) {
    ll now = i * p + s[n] - s[min(n,i*d)];
    ans = min(ans,now);
  }

  cout << ans << endl;
  return 0;
}