#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
const int INF = numeric_limits<int>::max();

int main() {
  int n; cin >> n;
  auto in = [&]() {
    vector g(n,vector<int>(n));
    int m; cin >> m;
    REP(i,m) {
      int u,v; cin >> u >> v; u--; v--;
      g[u][v] = g[v][u] = 1;
    }
    return g;
  };
  auto g = in();
  auto h = in();
  vector a(n,vector<int>(n));
  REP(i,n) for(int j = i+1; j < n; j++) cin >> a[i][j];
  REP(i,n) for(int j = i+1; j < n; j++) a[j][i] = a[i][j];

  auto f = [&](vector<int>& b) {
    int res = 0;
    REP(i,n) for(int j = i; j < n; j++) {
      if (g[i][j] != h[b[i]][b[j]]) res += a[b[i]][b[j]];
    }
    return res;
  };

  int ans = INF;
  vector<int> b(n);
  iota(b.begin(),b.end(),0);
  do {
    ans = min(ans,f(b));
  } while (next_permutation(b.begin(), b.end()));

  cout << ans << endl;
  return 0;
}
