#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;

ll extgcd(ll a, ll b, ll& x, ll& y) {
  if (b == 0) { x = 1; y = 0; return a; }
  auto d = extgcd(b,a-b*(a/b),y,x); // extgcd(b,a%b,y,x);
  y -= a/b * x;
  return d;
}

int main() {
  ll x,y; cin >> x >> y;
  ll b,a;
  auto g = extgcd(x,y,b,a);
  if (2%g) { cout << -1 << endl; return 0; }

  a = -a;
  a *= 2/g;
  b *= 2/g;
  cout << a << " " << b << endl;
  return 0;
}