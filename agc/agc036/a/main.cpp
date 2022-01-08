#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
using ll = long long;
const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;

set<ll> divisor(ll n) {
  set<ll> st;
  for (ll d = 1; d*d<n; d++) {
    if (n%d == 0) {
      st.insert(d);
      st.insert(n/d);
    }
  }
  return st;
}

int main() {
  ll s; cin >> s;
  int v = 1e9;

  // x1 = 0 , y1 = 0
  // x2 = 1e9, y2 = 1
  // x2*y3 - x3*y2 = s
  // x3 = (-s + x2*y3)/y2
  //    = (-s + 1e9*y3)
  // y3 = (s + x3*y2)/x2
  //    = (s + x3)/x2
  int x3 = (v-(s%v))%v;
  int y3 = (s+x3)/v;

  printf("0 0 %d 1 %d %d\n", v,x3,y3);
  return 0;
}