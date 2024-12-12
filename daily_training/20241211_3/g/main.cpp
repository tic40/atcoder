#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n,m; cin >> n >> m;
  vector g(n,vector<int>());
  REP(i,m) {
    int a,b; cin >> a >> b; a--; b--;
    g[a].push_back(b);
  }

  queue<int> q;
  vector<int> dist(n,1e9);
  dist[0] = 0;
  q.push(0);
  dist[0] = 1;
  while(q.size()) {
    int i = q.front(); q.pop();
    for(auto v: g[i]) {
      if (v == 0) { cout << dist[i] << endl; return 0; }
      if (dist[v] > dist[i]+1) {
        dist[v] = dist[i]+1;
        q.push(v);
      }
    }
  }
  cout << -1 << endl;
  return 0;
}