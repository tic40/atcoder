#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  vector<int> h(3),w(3);
  REP(i,3) cin >> h[i];
  REP(i,3) cin >> w[i];

  vector g(3,vector<int>(3));

  auto ok = [&]() {
    REP(j,2) {
      int sum = 0;
      REP(i,2) sum += g[i][j];
      int d = w[j] - sum;
      if (d <= 0) return 0;
      g[2][j] = d;
    }
    REP(i,2) {
      int sum = 0;
      REP(j,2) sum += g[i][j];
      int d = h[i] - sum;
      if (d <= 0) return 0;
      g[i][2] = d;
    }
    int v1 = h[2] - (g[2][0] + g[2][1]);
    int v2 = w[2] - (g[0][2] + g[1][2]);
    return (v1 > 0 && v2 > 0 && v1 == v2) ? 1 : 0;
  };

  int ans = 0;
  auto dfs = [&](auto dfs, int i) {
    if (i == 4) { ans += ok(); return; }
    for(int ni = 1; ni <= 30; ni++) {
      g[i/2][i%2] = ni;
      dfs(dfs,i+1);
    }
  };
  dfs(dfs,0);
  cout << ans << endl;
  return 0;
}