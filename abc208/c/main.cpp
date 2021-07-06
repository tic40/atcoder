#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
using ll = long long;

ll n,k;
vector<ll> a;

void solve() {
  ll m = k / n;
  k %= n;

  vector<ll> b = a;
  sort(b.begin(), b.end());
  map<int, ll> mp;
  REP(i,n) mp[b[i]] = (i < k) ? m+1 : m;
  REP(i,n) cout << mp[a[i]] << endl;
  return;
}

int main() {
  cin >> n >> k;
  a.resize(n);
  REP(i,n) cin >> a[i];

  solve();
  return 0;
}