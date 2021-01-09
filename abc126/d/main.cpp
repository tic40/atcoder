#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)

int n;
vector<vector<pair<int, int>>> g;
vector<int> dp;

void dfs(int cur, int d) {
  for (auto v: g[cur]) {
    int next = v.first;
    int w = v.second;

    if (dp[next] != -1) continue;

    dp[next] = (d+w)%2;
    dfs(next, dp[next]);
  }
  return;
}

void solve() {
  dp.resize(n,-1);
  dp[0] = 0;

  dfs(0,0);

  REP(i,n) cout << dp[i] << endl;
  return;
}

int main() {
  cin >> n;
  g.resize(n);

  REP(i,n-1) {
    int u,v,w;
    cin >> u >> v >> w;
    u--; v--;
    g[u].push_back({v,w});
    g[v].push_back({u,w});
  }

  solve();
  return 0;
}