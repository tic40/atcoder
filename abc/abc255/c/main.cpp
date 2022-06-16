#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
using ll = long long;

int main() {
  ll x,a,d,n;
  cin >> x >> a >> d >> n;

  if (d < 0) {
    a += d*(n-1);
    d = -d;
  }

  ll l = 0, r = n-1;
  while(abs(r-l)>1) {
    ll mid = (l+r)/2;
    ll now = a+d*mid;
    if (now < x) l = mid;
    else r = mid;
  }

  cout << min(abs(x - (a+d*l)), abs(x - (a+d*r))) << endl;;
  return 0;
}