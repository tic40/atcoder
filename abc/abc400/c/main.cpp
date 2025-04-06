#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;

int main() {
  ll n; cin >> n;
  ll ans = 0;
  for(int a = 1; a < 60; a++) {
    ll x = n;
    REP(i,a) x /= 2;
    ll m = sqrtl(x);
    ans += (m+1)/2;
  }
  cout << ans << endl;
  return 0;
}
