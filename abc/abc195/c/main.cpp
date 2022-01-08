#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
using ll = long long;
const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;

int main() {
  ll n, ans = 0; cin >> n;
  for(ll x: { 1e3, 1e6, 1e9, 1e12, 1e15 }) {
    if (x <= n) ans += n-(x-1);
  }
  cout << ans << endl;
  return 0;
}