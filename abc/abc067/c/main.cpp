#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
using ll = long long;
const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;

int main() {
  ll n; cin >> n;
  ll a[n], sum = 0;
  REP(i,n) { cin >> a[i]; sum+=a[i]; }

  ll ans = LINF, left=0;
  REP(i,n-1) {
    left+=a[i];
    ans = min(ans, abs(left * 2 - sum));
  }
  cout << ans << endl;
  return 0;
}