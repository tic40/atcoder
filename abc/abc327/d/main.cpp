#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n,m; cin >> n >> m;
  vector<int> a(m),b(m);
  REP(i,m) { cin >> a[i]; a[i]--; }
  REP(i,m) { cin >> b[i]; b[i]--; }

  REP(i,m) if (a[i] == b[i]) { cout << "No" << endl; return 0; }
  vector<vector<int>> g(n);
  REP(i,m) {
    g[a[i]].push_back(b[i]);
    g[b[i]].push_back(a[i]);
  }

  vector<int> col(n,-1);
  auto dfs = [&](auto self, int i) -> void {
    int nx = col[i] ^ 1;
    for(auto v: g[i]) {
      if (col[v] == -1 ) {
        col[v] = nx;
        self(self,v);
      }
      if (col[v] != nx) { cout << "No" << endl; exit(0); }
    }
  };

  REP(i,n) {
    if (col[i] != -1) continue;
    col[i] = 0;
    dfs(dfs,i);
  }
  cout << "Yes" << endl;
  return 0;
}