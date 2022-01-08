#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
using ll = long long;

ll f(ll x) {
  ll res = ((x+1) / 2) % 2;
  return x%2 == 0 ? res^x : res;
}

int main() {
  ll a,b; cin >> a >> b;

  cout << (f(a-1) ^ f(b)) << endl;
  return 0;
}