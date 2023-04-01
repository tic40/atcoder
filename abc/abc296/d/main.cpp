#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;
const ll LINF = numeric_limits<ll>::max();

int main() {
  ll n,m; cin >> n >> m;
  ll ans = LINF;
  for(ll a = 1; a <= min(n,(m+a-1)/a); a++) {
    ll b = (m+a-1)/a;
    if (b <= n) ans = min(ans,a*b);
  }

  cout << (ans == LINF ? -1 : ans) << endl;
  return 0;
}