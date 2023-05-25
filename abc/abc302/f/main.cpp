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

  vector g(m+n,vector<int>());
  REP(i,n) for(auto j: s[i]) {
    g[j].push_back(m+i);
    g[m+i].push_back(j);
  }

  auto bfs = [&]() {
    vector dist(n+m,INF);
    queue<int> q;
    q.push(0);
    dist[0] = 0;
    while(q.size()) {
      int v = q.front(); q.pop();
      for(auto nv: g[v]) {
        if (dist[nv] != INF) continue;
        dist[nv] = dist[v] + 1;
        q.push(nv);
      }
    }
    return dist;
  };

  auto dist = bfs();
  int ans = dist[m-1];
  cout << (ans == INF ? -1 : (ans-2)/2) << endl;
}