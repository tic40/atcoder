#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
using ll = long long;

int main() {
  vector<ll> x(3);
  REP(i,3) cin >> x[i];
  sort(x.rbegin(),x.rend());

  ll ans = x[0] > x[1] + x[2] ? -1 : x[0];
  cout << ans << endl;

  return 0;
}