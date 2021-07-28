#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
using ll = long long;
const int INF = 1e9;
const int MOD = 1e9+7;

int n,m;
vector<vector<int>> g;

void solve() {
  queue<int> q;
  q.push(0);
  vector<int> dist(n, INF);
  dist[0] = 0;

  vector<int> vs;
  while(q.size()) {
    int v = q.front(); q.pop();
    vs.push_back(v);
    for(int nv: g[v]) {
      if (dist[nv] != INF) continue;
      dist[nv] = dist[v]+1;
      q.push(nv);
    }
  }

  vector<ll> dp(n);
  dp[0] = 1;
  for (int v: vs) for (int u: g[v]) {
    if (dist[u] == dist[v]+1) {
      dp[u] += dp[v];
      dp[u] %= MOD;
    }
  }

  cout << dp[n-1] << endl;
  return;
}

int main() {
  cin >> n >> m;
  g.resize(n);
  REP(i,m) {
    int a,b;
    cin >> a >> b;
    a--; b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }

  solve();
  return 0;
}