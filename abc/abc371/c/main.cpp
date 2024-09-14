#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n; cin >> n;
  vector g1(n,vector<int>(n));
  vector g2(n,vector<int>(n));
  {
    int m; cin >> m;
    REP(i,m) {
      int u,v; cin >> u >> v; u--; v--;
      g1[u][v] = g1[v][u] = 1;
    }
  }
  {
    int m; cin >> m;
    REP(i,m) {
      int u,v; cin >> u >> v; u--; v--;
      g2[u][v] = g2[v][u] = 1;
    }
  }
  vector a(n,vector<int>(n));
  REP(i,n) for(int j = i+1; j < n; j++) cin >> a[i][j];

  int ans = 1e9;
  vector<int> b(n);
  iota(b.begin(),b.end(),0);
  do {
    int tot = 0;
    REP(i,n) for(int j = i; j < n; j++) {
      if (g1[i][j] == g2[b[i]][b[j]]) continue;
      tot += a[b[i]][b[j]];
      tot += a[b[j]][b[i]];
    }
    ans = min(ans,tot);
  } while (next_permutation(b.begin(), b.end()));

  cout << ans << endl;
  return 0;
}