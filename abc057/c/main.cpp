#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
using ll = long long;

int digits(ll n) {
  int d = 0;
  while(n > 0) { n /= 10; d++; }
  return d;
}

int main() {
  ll n; cin >> n;
  int ans = digits(n);
  for(ll i = 1; i*i <= n; i++) {
    if (n%i != 0) continue;
    ans = min(ans, max(digits(i), digits(n/i)));
  }
  cout << ans << endl;
  return 0;
}