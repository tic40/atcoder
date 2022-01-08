#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
using ll = long long;

ll n,m,p;

ll f(ll k) {
  if (k == 0) return 1;
  ll x = f(k/2);
  x = x%m*x%m;
  if (k%2) x = x*n%m;
  return x;
}

int main() {
  cin >> n >> m >> p;
  cout << f(p) << endl;
  return 0;
}