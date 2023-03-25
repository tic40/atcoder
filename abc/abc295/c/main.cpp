#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n; cin >> n;
  map<int,int> mp;
  REP(i,n) { int a; cin >> a; mp[a]++; }

  int ans = 0;
  for(auto [_,cnt]: mp) ans += cnt/2;
  cout << ans << endl;
  return 0;
}