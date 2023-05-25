#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
const int INF = numeric_limits<int>::max();

int main() {
  int n,m; cin >> n >> m;
  vector s(n,vector<int>());
  REP(i,n) {
    int a; cin >> a;
    REP(j,a) {
      int x; cin >> x; x--;
      s[i].push_back(x);
    }
  }

  vector g(n+m,vector<int>());
  REP(i,n) for(auto j: s[i]) {
    g[j].push_back(m+i);
    g[m+i].push_back(j);
  }

  vector<int> dist(n+m,INF);
  queue<int> q;
  dist[0] = 0;
  q.push(0);
  while(q.size()) {
    int v = q.front(); q.pop();
    for(int u: g[v]) {
      if (dist[u] != INF) continue;
      dist[u] = dist[v]+1;
      q.push(u);
    }
  }
  int ans = dist[m-1];
  cout << (ans == INF ? -1 : (ans-2)/2) << endl;
  return 0;
}