#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;

int main() {
  ll n; cin >> n;
  vector<ll> a(n);
  REP(i,n) cin >> a[i];

  ll s = accumulate(a.begin(),a.end(),0LL);
  ll x = s/n;
  ll r = s%n;
  vector<ll> b(n,x);
  REP(i,r) b[i]++;

  sort(a.begin(),a.end());
  sort(b.begin(),b.end());
  ll ans = 0;
  REP(i,n) ans += abs(a[i]-b[i]);
  cout << ans/2 << endl;
  return 0;
}