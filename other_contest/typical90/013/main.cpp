#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)

struct edge {
  int to;
  int cost;
};

int n,m;
vector<vector<edge>> g;

vector<int> bfs(int s) {
  vector<int> dist(n, 1e9);
  queue<int> q;
  q.push(s);
  dist[s] = 0;

  while(q.size()) {
    int cur = q.front();
    q.pop();

    for (auto nv: g[cur]) {
      int ndist = dist[cur] + nv.cost;
      if (ndist < dist[nv.to]) {
        dist[nv.to] = ndist;
        q.push(nv.to);
      }
    }
  }
  return dist;
}

void solve() {
  // 街1からのbfsと街nからのbfs
  auto dist1 = bfs(0);
  auto dist2 = bfs(n-1);

  REP(i,n) cout << dist1[i] + dist2[i] << endl;
  return;
}

int main() {
  cin >> n >> m;
  g.resize(n);

  int a,b,c;
  REP(i,m) {
    cin >> a >> b >> c;
    a--, b--;
    g[a].emplace_back(edge({b,c}));
    g[b].emplace_back(edge({a,c}));
  }

  solve();
  return 0;
}