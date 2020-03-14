#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
  int n; cin >> n;
  int a,ex=0,bit=0;

  REP(i,n) {
    cin >> a;
    if (a <= 399) bit|=(1<<1);
    else if (a <= 799) bit|=(1<<2);
    else if (a <= 1199) bit|=(1<<3);
    else if (a <= 1599) bit|=(1<<4);
    else if (a <= 1999) bit|=(1<<5);
    else if (a <= 2399) bit|=(1<<6);
    else if (a <= 2799) bit|=(1<<7);
    else if (a <= 3199) bit|=(1<<8);
    else ex++;
  }
  cout << max(1, __builtin_popcount(bit)) << " " << __builtin_popcount(bit)+ex << endl;
  return 0;
}