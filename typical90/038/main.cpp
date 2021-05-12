#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
using ll = long long;

ll a,b;

ll gcd(ll a, ll b) { return b?gcd(b,a%b):a; }
ll lcm(ll a, ll b) {
  ll l = a/gcd(a,b);

  if (( (ll)1e18+1) % b == 0) {
    if (l < ((ll)1e18+1)/b) return l*b;
  } else {
    if (l <= ((ll)1e18+1)/b) return l*b;
  }
  return -1;
}

int main() {
  cin >> a >> b;
  ll ans = lcm(a,b);

  if (ans == -1) cout << "Large" << endl;
  else cout << ans << endl;

  return 0;
}