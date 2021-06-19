#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
using ll = long long;

int n;
vector<int> a;

void solve() {
  ll ans = 0;
  map<int,int> mp;
  reverse(a.begin(), a.end());
  REP(i,n) {
    ans += i;
    if (mp[a[i]] > 0) ans -= mp[a[i]];
    mp[a[i]]++;
  }

  cout << ans << endl;
  return;
}

int main() {
  cin >> n;
  a.resize(n);
  REP(i,n) cin >> a[i];

  solve();
  return 0;
}