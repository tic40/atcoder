#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
const int INF = numeric_limits<int>::max();

int main() {
  int n1,n2,m; cin >> n1 >> n2 >> m;
  int n = n1+n2;
  vector g(n,vector<int>());
  REP(i,m) {
    int a,b; cin >> a >> b;
    a--; b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }

  auto bfs = [&](int i) {
    vector<int> dist(n,INF);
    queue<int> q;
    q.push(i);
    dist[i] = 0;
    while(q.size()) {
      int v = q.front(); q.pop();
      for(auto nv: g[v]) {
        if (dist[nv] <= dist[v]) continue;
        q.push(nv);
        dist[nv] = dist[v]+1;
      }
    }
    return dist;
  };

  auto d1 = bfs(0);
  auto d2 = bfs(n-1);
  int ans1 = *max_element(d1.begin(), d1.begin() + n1);
  int ans2 = *max_element(d2.begin() + n1, d2.end());
  int ans = ans1 + ans2 + 1;
  cout << ans << endl;
  return 0;
}