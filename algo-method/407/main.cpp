#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
using ll = long long;
const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;

int main() {
  ll n,x;
  cin >> n >> x;

  ll ng = 0, ok = n*n;
  while((ok - ng) > 1) {
    ll mid = (ng + ok) / 2;
    ll cnt = 0;
    for(ll i = 1; i <= n; i++) cnt += min(n, mid/i);
    if (x <= cnt) ok = mid;
    else ng = mid;
  }

  cout << ok << endl;
  return 0;
}