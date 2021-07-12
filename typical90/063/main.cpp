#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)

int h,w;
int p[10000][10000];

void solve() {
  int ans = 0;
  for(int bit = 1; bit < 1<<h; bit++) {
    vector<int> d;
    REP(j,h) if (bit >> j & 1) d.push_back(j);

    map<int,int> mp;
    REP(i,w) {
      int cur = -1, ok = true;
      for(int x: d) {
        if (cur == -1) cur = p[x][i];
        if (p[x][i] != cur) ok = false;
      }
      if (ok) mp[cur] += d.size();
    }
    int sum = 0;
    for(auto v: mp) sum = max(sum, v.second);
    ans = max(ans,sum);
  }

  cout << ans << endl;
  return;
}

int main() {
  cin >> h >> w;
  REP(i,h) REP(j,w) cin >> p[i][j];

  solve();
  return 0;
}