#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using P = pair<int,int>;

int main() {
  int n,m; cin >> n >> m;
  int mx = 1<<10;
  vector g(n,vector<P>());
  REP(i,m) {
    int a,b,w; cin >> a >> b >> w; a--; b--;
    g[a].emplace_back(b,w);
  }

  vector<bool> visited(n*mx);
  queue<int> q;
  q.push(0);
  visited[0] = true;
  while(q.size()) {
    int uid = q.front(); q.pop();
    int u = uid / mx;
    int x = uid % mx;
    for(auto [v,w]: g[u]) {
      int vid = v * mx + (x^w);
      if (visited[vid]) continue;
      visited[vid] = true;
      q.push(vid);
    }
  }

  int ans = -1;
  REP(x,mx) if (visited[(n-1) * mx + x]) {
    ans = x; break;
  }
  cout << ans << endl;
  return 0;
}