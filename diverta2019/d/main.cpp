#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
using ll = long long;
const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;

set<ll> divisor(ll n) {
  set<ll> st;
  for (ll d = 1; d*d<n; d++) {
    if (n%d == 0) {
      st.insert(d);
      st.insert(n/d);
    }
  }
  return st;
}

int main() {
  ll n,ans=0; cin >> n;

  auto d = divisor(n);
  for(auto x: d) {
    x--;
    if (0 < x && n/x == n%x) ans += x;
  }

  cout << ans << endl;
  return 0;
}