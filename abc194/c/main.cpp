#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(int)(n);i++)
#define ALL(x) x.begin(), x.end()
using ll = long long;
const int INF = 1e9;
const ll LINF = 1e18;
const int MOD = 1e9+7;

int main() {
  int n; cin >> n;
  vector<ll> a(n), b(n);
  REP(i,n) cin >> a[i];
  REP(i,n) b[i] = a[i]*a[i];

  vector<ll> as(n+1), bs(n+1);
  REP(i,n) as[i+1] = as[i]+a[i];
  REP(i,n) bs[i+1] = bs[i]+b[i];

  ll ans = 0;
  REP(i,n-1) {
    ans += b[i]*(n-1-i);
    ans += bs[n] - bs[i+1];
    ans -= 2*a[i]*(as[n]-as[i+1]);
  }
  cout << ans << endl;
  return 0;
}