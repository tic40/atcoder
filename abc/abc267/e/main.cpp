#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'
using ll = long long;

int main() {
  int n,m; cin >> n >> m;
  vector<int> a(n);
  REP(i,n) cin >> a[i];
  vector<vector<int>> g(n);
  REP(i,m) {
    int u,v; cin >> u >> v;
    u--; v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  vector<ll> cost(n);
  REP(i,n) for(int v: g[i]) cost[i] += a[v];

  ll ok = 1e15, ng = -1;
  while (abs(ok-ng)>1) {
    ll mid = (ok+ng)/2;
    queue<int> q;
    REP(i,n) if (cost[i] <= mid) q.push(i);

    vector<ll> tcost = cost;
    vector<bool> del(n);
    while(q.size()) {
      int i = q.front(); q.pop();
      if (del[i]) continue;
      del[i] = true;

      for(int v: g[i]) {
        if (!del[v]) {
          tcost[v] -= a[i];
          if (tcost[v] <= mid) q.push(v);
        }
      }
    }

    bool possible = true;
    for(bool v: del) if (!v) possible = false;

    if (possible) ok = mid;
    else ng = mid;
  }

  cout << ok << endl;
  return 0;
}