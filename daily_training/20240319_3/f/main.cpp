#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
const int INF = numeric_limits<int>::max();
using P = pair<int,int>;

int main() {
  int n; cin >> n;
  vector<int> x(n),y(n);
  REP(i,n) cin >> x[i] >> y[i];
  string s; cin >> s;

  map<int,P> mp;
  REP(i,n) mp[y[i]] = {INF,-INF};
  auto add = [&](int x, int y, char c) {
    if (c == 'R') mp[y].first = min(mp[y].first, x);
    if (c == 'L') mp[y].second = max(mp[y].second, x);
  };
  REP(i,n) add(x[i],y[i],s[i]);

  for(auto [k,v]: mp) {
    auto [l,r] = v;
    if (l < r) { cout << "Yes" << endl; return 0; }
  }
  cout << "No" << endl;
  return 0;
}