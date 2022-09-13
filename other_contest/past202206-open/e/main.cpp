#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'
using ll = long long;

int main() {
  ll n; cin >> n;
  ll x = (int)sqrtl(n);
  ll l = n - x*x;
  ll nx = x+1;

  if (l == 0) {
    cout << x << endl;
  } else if (l <= nx) {
    cout << nx-l+1 << endl;
  } else {
    cout << l-nx+1 << endl;
  }

  return 0;
}