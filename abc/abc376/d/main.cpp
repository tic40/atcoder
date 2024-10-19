#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
const int INF = numeric_limits<int>::max();

int main() {
  int n,m; cin >> n >> m;
  vector g(n,vector<int>());
  REP(i,m) {
    int a,b; cin >> a >> b; a--; b--;
    g[a].push_back(b);
  }

  vector<int> dist(n,INF);
  queue<int> q;
  q.push(0);
  dist[0] = 0;

  while(q.size()) {
    auto now = q.front(); q.pop();
    for(auto v: g[now]) {
      if (v == 0) { cout << dist[now]+1 << endl; return 0; }
      if (dist[v] <= dist[now]+1) continue;
      dist[v] = dist[now]+1;
      q.push(v);
    }
  }

  cout << -1 << endl;
  return 0;
}