#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
const int INF = numeric_limits<int>::max();

int main() {
  int n; cin >> n;
  vector g(n,vector<int>());
  vector<int> deg(n);
  REP(i,n-1) {
    int u,v; cin >> u >> v; u--; v--;
    g[u].push_back(v);
    g[v].push_back(u);
    deg[u]++;
    deg[v]++;
  }

  int ans = INF;
  REP(i,n) {
    sort(g[i].begin(),g[i].end(),[&](int a, int b) { return deg[a] > deg[b]; });
    REP(j,(int)g[i].size()) {
      int x = j+1;
      int y = deg[g[i][j]]-1;
      // 中心1個 + x個の頂点 + 葉の頂点(x*y) の木が作れる。よって削除する頂点は n からそれを引けば求まる
      ans = min(ans,n-(1+x+x*y));
    }
  }
  cout << ans << endl;
  return 0;
}