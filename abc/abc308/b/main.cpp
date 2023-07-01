#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n,m; cin >> n >> m;
  vector<string> c(n),d(m);
  vector<int> p(m+1);
  REP(i,n) cin >> c[i];
  REP(i,m) cin >> d[i];
  REP(i,m+1) cin >> p[i];

  map<string,int> mp;
  REP(i,m) mp[d[i]] = p[i+1];

  int ans = 0;
  REP(i,n) ans += mp.count(c[i]) ? mp[c[i]] : p[0];
  cout << ans << endl;
  return 0;
}