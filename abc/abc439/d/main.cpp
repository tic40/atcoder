#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;

int main() {
  int n; cin >> n;
  vector<int> a(n);
  REP(i,n) cin >> a[i];

  map<int,vector<int>> mp;
  REP(i,n) mp[a[i]].push_back(i);

  ll ans = 0;
  REP(j,n) {
    if (a[j] % 5 != 0) continue;
    ll c = a[j] / 5 * 7;
    ll d = a[j] / 5 * 3;

    if (!mp.count(c) || !mp.count(d)) continue;

    // j が min
    auto it1 = upper_bound(mp[c].begin(), mp[c].end(), j);
    auto it2 = upper_bound(mp[d].begin(), mp[d].end(), j);
    ll r1 = mp[c].end() - it1;
    ll r2 = mp[d].end() - it2;
    ans += r1*r2;

    // j が max
    auto it3 = lower_bound(mp[c].begin(), mp[c].end(), j);
    auto it4 = lower_bound(mp[d].begin(), mp[d].end(), j);
    ll r3 = it3 - mp[c].begin();
    ll r4 = it4 - mp[d].begin();
    ans += r3*r4;
  }
  cout << ans << endl;
  return 0;
}
