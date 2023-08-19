#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;

int main() {
  int n; cin >> n;
  vector<ll> f(n),s(n);
  REP(i,n) cin >> f[i] >> s[i];

  ll ans = 0;
  map<int,vector<ll>> mp;
  REP(i,n) mp[f[i]].push_back(s[i]);
  for(auto &[k,v]: mp) sort(v.rbegin(),v.rend());
  for(auto [k,v]: mp) {
    if (v.size() > 1) ans = max(ans,v[0]+v[1]/2);
  }
  vector<ll> mx;
  for(auto [k,v]: mp) mx.push_back(v[0]);
  if (mx.size() > 1) {
    sort(mx.rbegin(),mx.rend());
    ans = max(ans,mx[0]+mx[1]);
  }

  cout << ans << endl;
  return 0;
}