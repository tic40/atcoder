#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n; cin >> n;
  vector g(n,vector<int>());
  vector<int> deg(n);
  REP(i,n-1) {
    int u,v; cin >> u >> v;
    u--; v--;
    g[u].push_back(v);
    g[v].push_back(u);
    deg[u]++; deg[v]++;
  }

  vector<bool> del(n);
  // 頂点 i から 次数が 1 より大きい頂点を探す
  auto f = [&](int i) {
    if (i >= 0) for(auto v: g[i]) if (deg[v] > 1) return v;
    return -1;
  };

  vector<int> ans;
  queue<int> q;
  REP(i,n) if (deg[i] == 1) q.push(i);

  while(q.size()) {
    int now = q.front(); q.pop();
    int center = f(now);
    if (center == -1) continue;
    deg[center] = 0;
    for(auto v: g[center]) {
      deg[v]--;
      if (deg[v] == 1) q.push(f(v));
    }
    ans.push_back(g[center].size());
  }

  sort(ans.begin(),ans.end());
  for(int v: ans) cout << v << " ";
  return 0;
}