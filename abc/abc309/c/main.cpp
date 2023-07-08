#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;

int main() {
  int n,k; cin >> n >> k;
  map<int,ll> mp;
  REP(i,n) {
    int a,b; cin >> a >> b;
    mp[1] += b; mp[1+a] -= b;
  }

  ll p = 0;
  for(auto [i,v]: mp) {
    mp[i] += p;
    if (mp[i] <= k) { cout << i << endl; return 0; }
    p = mp[i];
  }

  return 0;
}