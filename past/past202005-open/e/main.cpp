#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(int)(n);i++)

int n,m,q;
vector<vector<int>> g;
vector<int> c;

int main() {
  cin >> n >> m >> q;
  g.resize(n);
  c.resize(n);
  REP(i,m) {
    int u,v; cin >> u >> v;
    u--; v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  REP(i,n) cin >> c[i];

  REP(i,q) {
    int t,x,y;
    cin >> t >> x;
    x--;

    if (t == 1) {
      cout << c[x] << endl;
      for(int v: g[x]) c[v] = c[x];
    } else {
      cin >> y;
      cout << c[x] << endl;
      c[x] = y;
    }
  }

  return 0;
}