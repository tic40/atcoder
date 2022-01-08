#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
using ll = long long;
const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;

int n;
ll a[105][6];

void solve() {
  ll ans = 1;
  REP(i,n) {
    ll p = 0;
    REP(j,6) p += a[i][j];
    ans *= p;
    ans %= MOD;
  }
  cout << ans;
  return;
}

int main() {
  cin >> n;
  REP(i,n) REP(j,6) cin >> a[i][j];

  solve();
  return 0;
}