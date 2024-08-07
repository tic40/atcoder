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

  int q; cin >> q;
  vector<int> dist(n,INF);
  REP(_,q) {
    int x,k; cin >> x >> k;
    x--;

    queue<int> q;
    q.push(x);
    dist[x] = 0;
    vector<int> vs;

    while(q.size()) {
      int i = q.front(); q.pop();
      vs.push_back(i);
      if (dist[i] >= k) continue;
      for(auto v: g[i]) if (dist[v] > dist[i]+1) {
        dist[v] = dist[i]+1;
        q.push(v);
      }
    }

    int ans = 0;
    for(auto v: vs) { ans += v+1; dist[v] = INF; }
    cout << ans << endl;
  }
  return 0;
}