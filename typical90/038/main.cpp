#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
using ll = long long;

ll a,b;

ll gcd(ll a, ll b) { return b?gcd(b,a%b):a; }
ll lcm(ll a, ll b) { return a/gcd(a,b)*b; }

int main() {
  cin >> a >> b;
  ll mx = 1e18;
  ll ans = lcm(a,b);

  ll r = a / gcd(a,b);
  if (r > mx/b) cout << "Large" << endl;
  else cout << r * b << endl;

  return 0;
}