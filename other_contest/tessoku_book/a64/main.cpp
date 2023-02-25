#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using P = pair<int, int>;
const int INF = 1e9+5;

int main() {
  int n,m; cin >> n >> m;
  vector g(n,vector<P>());
  REP(i,m) {
    int a,b,c; cin >> a >> b >> c;
    a--; b--;
    g[a].emplace_back(b,c);
    g[b].emplace_back(a,c);
  }

  priority_queue<P, vector<P>, greater<P>> q;
  vector<int> dist(n,INF);
  auto push = [&](int i, int d) {
    if (dist[i] <= d) return;
    dist[i] = d;
    q.emplace(d,i);
  };

  push(0,0);
  while(q.size()) {
    auto [d,i] = q.top(); q.pop();
    if (dist[i] < d) continue;
    for(auto [ni,nc]: g[i]) push(ni,d+nc);
  }

  for(int v: dist) cout << (v == INF ? -1 : v) << endl;
  return 0;
}