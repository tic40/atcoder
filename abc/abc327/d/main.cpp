#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n,m; cin >> n >> m;
  vector<int> a(m),b(m);
  REP(i,m) { cin >> a[i]; a[i]--; }
  REP(i,m) { cin >> b[i]; b[i]--; }
  vector g(n,vector<int>());
  REP(i,m) {
    g[a[i]].push_back(b[i]);
    g[b[i]].push_back(a[i]);
  }

  vector<int> col(n,-1);
  auto dfs = [&](auto self, int i) -> bool {
    bool res = true;
    int nc = col[i] ^ 1;
    for(auto v: g[i]) {
      if (col[v] == -1) {
        col[v] = nc;
        res = res && self(self,v);
      }
      if (col[v] == col[i]) return false;
    }
    return res;
  };

  REP(i,n) {
    if (col[i] != -1) continue;
    col[i] = 0;
    if (!dfs(dfs,i)) { cout << "No" << endl; return 0; }
  }
  cout << "Yes" << endl;
  return 0;
}