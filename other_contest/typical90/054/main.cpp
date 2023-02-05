#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
const int INF = numeric_limits<int>::max();

int main() {
  int n,m; cin >> n >> m;
  vector<vector<int>> g(n+m);
  REP(i,m) {
    int k; cin >> k;
    REP(j,k) {
      int x; cin >> x;
      x--;
      g[x].push_back(n+i);
      g[n+i].push_back(x);
    }
  }

  vector<int> dist(n+m,INF);
  queue<int> q;
  auto push = [&](int i, int nd) {
    if (dist[i] <= nd) return;
    q.push(i);
    dist[i] = nd;
  };

  push(0,0);
  while(q.size()) {
    int now = q.front(); q.pop();
    int nd = dist[now]+1;
    for(auto v: g[now]) push(v,nd);
  }

  REP(i,n) cout << (dist[i] == INF ? -1 : dist[i]/2) << endl;
  return 0;
}