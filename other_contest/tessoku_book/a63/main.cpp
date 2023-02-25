#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
const int INF = numeric_limits<int>::max();

int main() {
  int n,m; cin >> n >> m;
  vector g(n,vector<int>());
  REP(i,m) {
    int a,b; cin >> a >> b;
    a--; b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }

  queue<int> q;
  q.push(0);

  vector<int> dist(n,INF);
  dist[0] = 0;
  while(q.size()) {
    int v = q.front(); q.pop();
    int nd = dist[v]+1;
    for(int nv: g[v]) {
      if (nd >= dist[nv]) continue;
      dist[nv] = nd;
      q.push(nv);
    }
  }

  for(int v: dist) cout << (v == INF ? -1 : v) << endl;
  return 0;
}