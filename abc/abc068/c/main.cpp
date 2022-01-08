#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
using ll = long long;
using Graph = vector<vector<int>>;

int main() {
  int n,m; cin >> n >> m;
  Graph G(n);
  vector<int> dist(n, 0);

  int a,b;
  REP(i,m) {
    cin >> a >> b;
    a--; b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }

  queue<int> q; q.push(0);
  while(!q.empty()) {
    int t = q.front(); q.pop();
    for (int x : G[t]) {
      if (dist[x] > 0) continue;
      dist[x] = dist[t]+1;
      q.push(x);
    }
  }

  if (0 < dist[n-1] && dist[n-1] < 3) {
    cout << "POSSIBLE" << endl;
  } else {
    cout << "IMPOSSIBLE" << endl;
  }
  return 0;
}