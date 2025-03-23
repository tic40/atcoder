#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using P = pair<int,int>;

int main() {
  int n; cin >> n;
  vector g(n,vector<int>());
  vector<P> es;
  REP(i,n-1) {
    int u,v; cin >> u >> v; u--; v--;
    g[u].push_back(v);
    g[v].push_back(u);
    es.emplace_back(u,v);
  }

  vector<int> col(n);
  auto dfs = [&](auto& dfs, int i, int p) -> void {
    for(auto v: g[i]) if (v != p) {
      col[v] = col[i]^1;
      dfs(dfs,v,i);
    }
  };
  dfs(dfs,0,-1);

  vector<int> x,y;
  REP(i,n) col[i] == 0 ? x.push_back(i) : y.push_back(i);
  int tot = x.size() * y.size() - (n-1);
  int t = tot%2;
  cout << (t == 1 ? "First" : "Second") << endl;

  set<P> st;
  for(auto a: x) for(auto b: y) st.emplace(min(a,b),max(a,b));
  for(auto e: es) st.erase(e);

  while(1) {
    if (t == 1) {
      auto [u,v] = *st.begin();
      cout << u+1 << " " << v+1 << endl;
      st.erase(st.begin());
    }
    if (t == 0) {
      int u,v; cin >> u >> v; u--; v--;
      if (u == -2) break;
      st.erase(P{u,v});
    }
    t^=1;
  }
  return 0;
}
