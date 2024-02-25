#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
const int INF = numeric_limits<int>::max();

int main() {
  int n1,n2,m;
  cin >> n1 >> n2 >> m;
  int n = n1+n2;
  vector g(n,vector<int>());
  REP(i,m) {
    int a,b; cin >> a >> b;
    a--; b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }

  auto bfs = [&](int i) {
    vector<int> dist(n,INF);
    queue<int> q;
    q.push(i);
    dist[i] = 0;
    while(q.size()) {
      int v = q.front(); q.pop();
      for(auto nv: g[v]) {
        if (dist[nv] <= dist[v]+1) continue;
        q.push(nv);
        dist[nv] = dist[v]+1;
      }
    }

    int res = 0;
    REP(i,n) { if (dist[i] != INF) res = max(res,dist[i]); }
    return res;
  };

  int ans = bfs(0) + bfs(n-1) + 1;
  cout << ans << endl;
  return 0;
}