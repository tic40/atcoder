#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int h,w; cin >> h >> w;
  vector p(h,vector<int>(w));
  REP(i,h) REP(j,w) cin >> p[i][j];

  auto f = [&](vector<int>& v) {
    map<int,int> mp;
    REP(j,w) {
      bool ok = true;
      int now = p[v[0]][j];
      for(int i: v) if (now != p[i][j]) { ok = false; break; }
      if (ok) mp[now] += v.size();
    }
    return mp;
  };

  int ans = 0;
  for(int bit = 1; bit < 1<<h; bit++) {
    vector<int> v;
    REP(j,h) if (bit >> j & 1) v.push_back(j);
    auto mp = f(v);
    for(auto [_,cnt]: mp) ans = max(ans,cnt);
  }
  cout << ans << endl;
  return 0;
}