#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'

int main() {
  int n,m; cin >> n >> m;
  vector a(n, vector<int> (n));
  REP(i,m) {
    int u,v; cin >> u >> v;
    u--; v--;
    a[u][v] = a[v][u] = 1;
  }

  int ans = 0;
  REP(i,n) {
    for(int j = i+1; j < n; j++) {
      for(int k = j+1; k < n; k++) {
        if (a[i][j] && a[j][k] && a[k][i]) ans++;
      }
    }
  }

  cout << ans << endl;
  return 0;
}