#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
using ll = long long;

int main() {
  int n,m; cin >> n >> m;
  vector<int> a(n);
  REP(i,n) cin >> a[i];

  vector<ll> w(n+1);
  REP(i,n) w[i+1] += (w[i]+a[i]) % m;

  ll ans = 0;
  map<ll, int> mp;
  REP(i,n+1) {
    ans += mp[w[i]];
    mp[w[i]]++;
  }

  cout << ans << endl;
  return 0;
}