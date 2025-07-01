#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
const int INF = numeric_limits<int>::max();

int main() {
  int n,m; cin >> n >> m;
  vector g(n,vector<int>(n));
  REP(i,m) {
    int a,b; cin >> a >> b; a--; b--;
    g[a][b] = g[b][a] = 1;
  }

  vector<int> b(n);
  iota(b.begin(),b.end(),0);
  auto solve = [&](int d) {
    int res = 0;
    vector h(n,vector<int>(n));
    REP(i,d) {
      int u = b[i], v = b[(i+1)%d];
      h[u][v] = h[v][u] = 1;
    }
    for(int i = d; i < n; i++) {
      int u = b[i], v = b[i+1 >= n ? d : i+1];
      h[u][v] = h[v][u] = 1;
    }
    REP(i,n) for(int j = i+1; j < n; j++) if (g[i][j] != h[i][j]) res++;
    return res;
  };

  int ans = INF;
  do {
    ans = min(ans,solve(n));
    for(int d = 3; d <= n-3; d++) ans = min(ans,solve(d));
  } while(next_permutation(b.begin(),b.end()));

  cout << ans << endl;
  return 0;
}