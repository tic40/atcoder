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

  int ans = INF;
  vector<int> b(n);
  iota(b.begin(),b.end(),0);

  auto cycle1 = [&]() {
    vector f(n,vector<int>(n));
    REP(i,n) {
      int u = b[i], v = b[(i+1)%n];
      f[u][v] = f[v][u] = 1;
    }
    int res = 0;
    REP(i,n) for(int j = i+1; j < n; j++) if(g[i][j] != f[i][j]) res++;
    return res;
  };

  auto cycle2 = [&]() {
    int res = INF;
    for(int d = 3; d <= n-3; d++) {
      vector f(n,vector<int>(n));
      REP(i,d) {
        int u = b[i], v = b[(i+1)%d];
        f[u][v] = f[v][u] = 1;
      }
      for(int i = d; i < n; i++) {
        int u = b[i], v = b[i+1 >= n ? d : i+1];
        f[u][v] = f[v][u] = 1;
      }
      int now = 0;
      REP(i,n) for(int j = i+1; j < n; j++) if(g[i][j] != f[i][j]) res++;
      res = min(res,now);
    }
    return res;
  };

  do {
    ans = min({ans,cycle1(),cycle2()});
  } while (next_permutation(b.begin(), b.end()));

  cout << ans << endl;
  return 0;
}