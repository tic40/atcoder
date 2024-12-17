#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;

int main() {
  int n; cin >> n;
  vector<int> a(n);
  REP(i,n) cin >> a[i];

  const int m = 25;
  vector<ll> d(m);
  REP(k,m) {
    int mod = 1<<k;
    vector<ll> sum(mod),cnt(mod);
    ll now = 0;
    REP(i,n) {
      sum[a[i]%mod] += a[i];
      cnt[a[i]%mod]++;
      int b = (mod-a[i]%mod) % mod;
      now += sum[b];
      now += cnt[b]*a[i];
    }
    d[k] = now;
  }

  REP(k,m-1) d[k] -= d[k+1];

  ll ans = 0;
  REP(k,m) ans += d[k]>>k;
  cout << ans << endl;
  return 0;
}