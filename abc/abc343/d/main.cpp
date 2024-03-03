#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;

int main() {
  int n,t; cin >> n >> t;
  vector<ll> m(n);
  map<ll,int> mp;
  mp[0] = n;

  REP(_,t) {
    int a,b; cin >> a >> b; a--;
    ll before = m[a], after = m[a]+b;
    mp[before]--; mp[after]++;
    if (mp[before] == 0) mp.erase(before);
    m[a] = after;
    cout << mp.size() << endl;
  }
  return 0;
}