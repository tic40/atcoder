#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;

int main() {
  ll b; cin >> b;
  ll ans = -1;
  for(ll x = 1; x <= 15; x++) {
    ll v = powl(x,x);
    if (v == b) { ans = x; break; }
  }
  cout << ans << endl;
  return 0;
}