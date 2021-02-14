#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
using ll = long long;
const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;

int main() {
  ll a,b,x;
  cin >> a >> b >> x;
  ll ans = b/x - max(0LL, a-1)/x;

  if (a == 0) { cout << ans + 1 << endl; }
  else cout << ans << endl;

  return 0;
}