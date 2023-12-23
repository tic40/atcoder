#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;

int main() {
  ll a,m,l,r; cin >> a >> m >> l >> r;
  l -= a; r -= a;
  ll ans = 0;

  if (0 < l) {
    ans += abs(r) / m;
    ans -= abs(l-1) / m;
  } else if (r < 0) {
    ans += abs(l) / m;
    ans -= abs(r+1) / m;
  } else {
    ans++;
    ans += abs(r) / m;
    ans += abs(l) / m;
  }

  cout << ans << endl;
  return 0;
}