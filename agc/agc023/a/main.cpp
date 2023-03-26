#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;

int main() {
  int n; cin >> n;
  vector<int> a(n);
  REP(i,n) cin >> a[i];
  vector<ll> s(n+1);
  REP(i,n) s[i+1] = s[i] + a[i];

  map<ll,int> mp;
  REP(i,n+1) mp[s[i]]++;
  ll ans = 0;
  for(auto [_,cnt]: mp) ans += (ll)cnt * (cnt-1) / 2;
  cout << ans << endl;
  return 0;
}