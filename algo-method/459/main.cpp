#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(int)(n);i++)
#define ALL(x) x.begin(), x.end()
using ll = long long;
const int INF = 1e9;
const ll LINF = 1e18;
const int MOD = 1e9+7;

ll legendre(ll n, ll x) {
  ll res = 0;
  while(n) {
    res += n/x;
    n /= x;
  }
  return res;
}

int main() {
  ll n; cin >> n;

  cout << legendre(n,(ll)5) << endl;
  return 0;
}