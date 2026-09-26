#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;
using P = pair<int,int>;
const int INF = numeric_limits<int>::max();
const ll LINF = numeric_limits<ll>::max();
const int MOD = 1e9+7;
// using mint = modint998244353; // modint1000000007;

int main() {
  int n; cin >> n;
  vector<int> a(n),b(n),c(n);
  REP(i,n) cin >> a[i];
  REP(i,n) cin >> b[i];
  REP(i,n) cin >> c[i];

  vector<ll> sa(n+1),sb(n+1),sc(n+1);
  REP(i,n) sa[i+1] = sa[i]+a[i];
  REP(i,n) sb[i+1] = sb[i]+b[i];
  REP(i,n) sc[i+1] = sc[i]+c[i];

  vector<ll> prefixmax(n,-1e12);
  for(int x = 1; x < n-1; x++) {
    prefixmax[x] = max(prefixmax[x-1], sa[x] - sb[x]);
  }

  ll ans = 0;
  for(int y = 2; y < n; y++) {
    // sa[x] + (sb[y] - sb[x]) + (sc[n] - sc[y])
    // sa[x] - sb[x] + sb[y] - sc[y] + sc[n]
    ll now = sb[y] - sc[y] + sc[n] + prefixmax[y-1];
    ans = max(ans, now);
  }
  cout << ans << endl;
  return 0;
}
