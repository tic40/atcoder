#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
using ll = long long;
const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;

int main() {
  ll n; cin >> n;

  int mx = 0;
  for (int i = 1; i*i <= n; i++) {
    if (n%i == 0) mx = n/i;
  }

  int ans = 0;
  while(0 < mx) {
    mx /= 10;
    ans++;
  }

  cout << ans << endl;
  return 0;
}