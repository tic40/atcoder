#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
using ll = long long;

int main() {
  int n; cin >> n;

  ll a = 0;
  REP(i,n) {
    int t; cin >> t;
    if (t == 0) {
      a += (a%2) ? 2 : 1;
      continue;
    }

    ll mn = 1LL<<t;
    if (a < mn) a = mn;
    else {
      REP(j,t) a &= ~(1LL<<j);
      a += (a >> t & 1) ? 1LL<<(t+1) : 1LL<<t;
    }
  }

  cout << a << endl;
  return 0;
}