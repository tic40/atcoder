#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;
using P = pair<int,int>;
const int INF = 1e9; // numeric_limits<int>::max();
const ll LINF = numeric_limits<ll>::max();
const int MOD = 1e9+7;

int main() {
  int n,m; cin >> n >> m;
  vector g(n,vector<int>());
  REP(i,m) {
    int u,v; cin >> u >> v;
    u--; v--;
    g[u].push_back(v);
  }

  queue<int> q;
  vector<int> dist(n,INF);
  auto push = [&](int i, int d) {
    if (d >= dist[i]) return;
    dist[i] = d;
    q.push(i);
  };

  ll ans = 0;
  REP(i,n) {
    REP(i,n) dist[i] = INF;
    push(i,0);
    while(q.size()) {
      int v = q.front(); q.pop();
      int nd = dist[v]+1;
      for(int nv: g[v]) push(nv,nd);
    }

    // bfs2
    queue<P> q2;
    auto push2 = [&](int to, int nd) {
      if (dist[to] != nd) return;
      ans++;
      // g[i].push_back(to);
      q2.emplace(to,nd);
    };
    REP(j,n) if (dist[j] == 2) push2(j,2);
    while(q2.size()) {
      auto [now,nd] = q2.front(); q2.pop();
      for(int nv: g[now]) push2(nv,nd+1);
    }
  }
  cout << ans << endl;
  return 0;
}