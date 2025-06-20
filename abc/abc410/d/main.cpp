#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using P = pair<int,int>;

int main() {
  int n,m; cin >> n >> m;
  const int MX = 1<<10;
  vector g(n,vector<P>());
  REP(i,m) {
    int a,b,w; cin >> a >> b >> w; a--; b--;
    g[a].emplace_back(b,w);
  }

  vector<bool> visited(n * MX);
  queue<int> q;

  auto push = [&](int v, int x) -> void {
    int vid = v * MX + x;
    if (visited[vid]) return;
    visited[vid] = true;
    q.push(vid);
  };

  push(0,0);
  while(q.size()) {
    int uid = q.front(); q.pop();
    int u = uid / MX;
    int x = uid % MX;
    for(auto [v,w]: g[u]) push(v,x^w);
  }

  int ans = -1;
  REP(x,MX) if (visited[(n-1) * MX + x]) { ans = x; break; }
  cout << ans << endl;
  return 0;
}