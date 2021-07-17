#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
using ll = long long;

int n,k;
vector<ll> c;

void solve() {
  map<int,int> mp;
  REP(i,k) mp[c[i]]++;
  ll ans = mp.size();
  ll cur = ans;

  REP(i,n-k) {
    int l = i, r = i+k;
    mp[c[l]] = max(0, mp[c[l]]-1);

    if (mp[c[l]] == 0) cur--;
    mp[c[r]]++;
    if (mp[c[r]] == 1) cur++;
    ans = max(cur, ans);
  }

  cout << ans << endl;
  return;
}

int main() {
  cin >> n >> k;
  c.resize(n);
  REP(i,n) cin >> c[i];

  solve();
  return 0;
}