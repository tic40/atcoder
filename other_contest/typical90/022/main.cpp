#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'
using ll = long long;

int main() {
  ll a,b,c; cin >> a >> b >> c;
  ll x = gcd(a,gcd(b,c));
  ll ans = (a+b+c)/x - 3;
  cout << ans << endl;
  return 0;
}