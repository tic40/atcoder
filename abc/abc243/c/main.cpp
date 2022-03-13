#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(int)(n);i++)
const int INF = 1e9+5;

int main() {
  int n; cin >> n;
  vector<int> x(n),y(n);
  REP(i,n) cin >> x[i] >> y[i];
  string s; cin >> s;

  map<int,pair<int,int>> mp;
  REP(i,n) mp[y[i]] = { INF, -INF };
  REP(i,n) {
    if (s[i] == 'R') mp[y[i]].first = min( mp[y[i]].first, x[i] );
    if (s[i] == 'L') mp[y[i]].second = max( mp[y[i]].second, x[i] );
  }

  bool ok = false;
  for(auto [k,v]: mp) ok |= (v.first < v.second);
  cout << (ok ? "Yes" : "No") << endl;
  return 0;
}