#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;

int main() {
  ll n, ans = 0;
  cin >> n;
  if (n % 2 == 1) { cout << 0 << endl; return 0; }

  for (ll i = 1; i < 26; i++) {
    ll p = pow(5, i);
    if (n < p) break;
    ans += n / (p * 2);
  }
  cout << ans << endl;
}