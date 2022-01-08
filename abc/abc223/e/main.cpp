#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(int)(n);i++)
#define ALL(x) x.begin(), x.end()
using ll = long long;

ll divCeil(ll a, ll b) { return (a+b-1)/b; }

bool f2(ll x, ll y, ll a, ll b) {
  ll w = divCeil(a,y) + divCeil(b,y);
  return w <= x;
}

bool f3(ll x, ll y, ll a, ll b, ll c) {
  ll w = divCeil(a,y);
  if (w >= x) return false;
  x -= w;
  return f2(x,y,b,c) || f2(y,x,b,c);
}

int main() {
  ll x,y;
  cin >> x >> y;
  ll a,b,c;
  cin >> a >> b >> c;

  REP(fi,2) {
    REP(ri,3) {
      if (f3(x,y,a,b,c)) {
        cout << "Yes" << endl;
        return 0;
      }
      // rotate
      swap(a,b); swap(b,c);
    }
    swap(x,y);
  }

  cout << "No" << endl;
  return 0;
}