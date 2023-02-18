#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;

int main() {
  ll n,m,b; cin >> n >> m >> b;
  vector<ll> a(n),c(m);
  REP(i,n) cin >> a[i];
  REP(i,m) cin >> c[i];

  ll sa = accumulate(a.begin(),a.end(),0LL);
  ll sc = accumulate(c.begin(),c.end(),0LL);

  ll ans = sa * m;
  ans += sc * n;
  ans += b * n * m;
  cout << ans << endl;
  return 0;
}