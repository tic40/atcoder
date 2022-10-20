#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'

int main() {
  int h,w; cin >> h >> w;
  vector p(h,vector<int>(w));
  REP(i,h) REP(j,w) cin >> p[i][j];

  int ans = 0;
  REP(hbit,1<<h) {
    map<int,int> mp;
    vector<int> d;
    REP(i,h) if (hbit>>i & 1) d.push_back(i);

    REP(j,w) {
      int now = -1;
      bool ok = true;
      for(int i: d) {
        if (now == -1) now = p[i][j];
        if (now != p[i][j]) ok = false;
      }
      if (ok) mp[now] += d.size();
    }
    for(auto [k,v]: mp) ans = max(ans,v);
  }

  cout << ans << endl;
  return 0;
}