#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n1,n2,m; cin >> n1 >> n2 >> m;
  int n = n1+n2;
  vector g(n,vector<int>());
  REP(i,m) {
    int a,b; cin >> a >> b; a--; b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }

  auto bfs = [&](int start) {
    vector<int> dist(n,-1);
    queue<int> q;
    q.push(start);
    dist[start] = 0;
    while(q.size()) {
      auto u = q.front(); q.pop();
      for(auto v: g[u]) if (dist[v] == -1) {
        dist[v] = dist[u]+1;
        q.push(v);
      }
    }
    return *max_element(dist.begin(),dist.end());
  };

  int ans = bfs(0) + bfs(n-1) + 1;
  cout << ans << endl;
  return 0;
}
