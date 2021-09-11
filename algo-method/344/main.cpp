#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
using ll = long long;

int main() {
  ll n; cin >> n;
  int ans = 0;
  for (ll i = 1; i*i <= n; i++) {
    if (n%i == 0) {
      ans++;
      if (n/i != i) ans++;
    }
  }
  cout << ans << endl;
  return 0;
}