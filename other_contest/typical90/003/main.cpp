#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
const int INF = numeric_limits<int>::max();
#define endl '\n'

int main() {
  int n; cin >> n;
  vector g(n,vector<int>());
  REP(i,n-1) {
    int a,b; cin >> a >> b;
    a--; b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }

  auto bfs = [&](int i) -> vector<int> {
    vector<int> dist(n,INF);
    queue<int> q;
    q.push(i);
    dist[i] = 0;
    while(q.size()) {
      int now = q.front(); q.pop();
      for(int v: g[now]) {
        if (dist[v] != INF) continue;
        dist[v] = dist[now]+1;
        q.push(v);
      }
    }
    return dist;
  };

  auto dist1 = bfs(0);
  int idx = max_element(dist1.begin(),dist1.end()) - dist1.begin();
  auto dist2 = bfs(idx);
  int ans = *max_element(dist2.begin(),dist2.end()) + 1;
  cout << ans << endl;

  return 0;
}