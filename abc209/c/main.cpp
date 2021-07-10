#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
using ll = long long;
const int MOD = 1e9+7;

ll n;
vector<ll> c;

void solve() {
  sort(c.begin(), c.end());
  ll ans = 1;
  REP(i,n) {
    ans *= (c[i] - i);
    ans %= MOD;
  }

  cout << ans << endl;
  return;
}

int main() {
  cin >> n;
  c.resize(n);
  REP(i,n) cin >> c[i];

  solve();
  return 0;
}