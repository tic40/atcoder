#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(int)(n);i++)
#define ALL(x) x.begin(), x.end()
using ll = long long;
const int INF = 1e9;
const ll LINF = 1e18;
const int MOD = 1e9+7;

int main() {
  int n,k; cin >> n >> k;
  vector<ll> a(n);
  REP(i,n) cin >> a[i];
  sort(a.begin(), a.end());

  ll ans = LINF;
  REP(i,n-(k-1)) ans = min(ans, a[i+k-1] - a[i]);
  cout << ans << endl;
  return 0;
}