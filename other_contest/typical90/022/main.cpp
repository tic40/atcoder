#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;

int main() {
  ll a,b,c; cin >> a >> b >> c;
  ll d = gcd(gcd(a,b),c);
  ll ans = (a+b+c) / d - 3LL;
  cout << ans << endl;
  return 0;
}