#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;

int main() {
  int n; cin >> n;
  map<ll,ll> mp;
  REP(i,n) {
    int s,c; cin >> s >> c;
    mp[s] += c;
  }

  int ans = 0;
  for(auto [size,cnt]: mp) {
    mp[size*2] += cnt/2;
    ans += cnt % 2;
  }
  cout << ans << endl;
  return 0;
}