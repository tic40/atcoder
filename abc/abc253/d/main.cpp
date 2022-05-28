#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
using ll = long long;

int main() {
  ll n,a,b; cin >> n >> a >> b;

  ll ans = (1+n)*n/2;
  ans -= (a+n/a*a)*(n/a)/2;
  ans -= (b+n/b*b)*(n/b)/2;
  ll l = lcm(a,b);
  ans += (l+n/l*l)*(n/l)/2;

  cout << ans << endl;
  return 0;
}
