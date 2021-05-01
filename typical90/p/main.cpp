#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
using ll = long long;
const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;

int main() {
  ll n,a,b,c;
  cin >> n >> a >> b >> c;

  int ans = 10000;
  REP(i,10000) REP(j,10000-i) {
    ll d = n - (a*i+b*j);
    int r = i+j+d/c;
    if (d%c == 0 && 0 <= d) ans = min(ans, r);
  }

  cout << ans << endl;
  return 0;
}