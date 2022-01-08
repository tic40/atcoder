#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
using ll = long long;

bool ok(ll x, ll y, ll r) {
  return x*x+y*y <= r*r;
}

ll f(ll x, ll y, ll r, ll lim) {
  ll res = 0;
  ll left = 0 , right = 1;
  for (int i = 1e9; lim <= i; i -= 10000) {
    while(ok(x-left*10000, i-y, r)) left--;
    while(ok(right*10000-x, i-y, r)) right++;
    res += right-left-1;
  }
  return res;
}

int main() {
  double _x, _y, _r;
  cin >> _x >> _y >> _r;
  ll x = round(_x*10000);
  ll y = round(_y*10000);
  ll r = round(_r*10000);

  x %= 10000;
  y %= 10000;

  ll ans = f(x,y,r,10000);
  ans += f(x,-y,r,0);

  cout << ans << endl;
  return 0;
}