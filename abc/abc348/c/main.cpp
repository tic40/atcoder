#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n; cin >> n;
  unordered_map<int,int> mp;
  REP(i,n) {
    int a,c; cin >> a >> c; c--;
    mp[c] = mp.find(c) == mp.end() ? a : min(mp[c],a);
  }
  int ans = -1;
  for(auto [k,v]: mp) ans = max(ans,v);
  cout << ans << endl;
  return 0;
}