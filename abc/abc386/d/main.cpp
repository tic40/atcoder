#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using P = pair<int,int>;
const int INF = numeric_limits<int>::max();

int main() {
  int n,m; cin >> n >> m;
  map<P,char> mp;
  REP(i,m) {
    int x,y; char c; cin >> x >> y >> c;
    mp[P{x,y}] = c;
  }

  int ok = 1;
  int min_y = INF;
  for(auto [pa,c]: mp) {
    auto [x,y] = pa;
    if (c == 'W') min_y = min(min_y,y);
    else ok &= min_y > y;
  }
  cout << (ok ? "Yes" : "No") << endl;
  return 0;
}