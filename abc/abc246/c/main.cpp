#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
using ll = long long;

int main() {
  int n,k,x;
  cin >> n >> k >> x;
  vector<int> a(n);
  REP(i,n) cin >> a[i];

  REP(i,n) {
    int t = min(k, a[i]/x);
    a[i] -= t*x;
    k -= t;
  }

  sort(a.rbegin(),a.rend());
  REP(i,n) {
    if (k == 0) break;
    a[i] = max(a[i]-x, 0);
    k--;
  }

  ll ans = 0;
  REP(i,n) ans += a[i];
  cout << ans << endl;
  return 0;
}
