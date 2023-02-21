#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;

int main() {
  int n; cin >> n;
  map<int,int> mp;
  REP(i,n) {
    int a; cin >> a;
    mp[a]++;
  }

  ll ans = 0;
  for(auto [_,v]: mp) ans += (ll)v * (v-1) / 2;
  cout << ans << endl;
  return 0;
}