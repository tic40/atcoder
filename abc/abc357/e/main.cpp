#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;

// use scc library
void solve1(int n) {
  scc_graph g(n);
  vector<int> to(n);
  REP(i,n) {
    int a; cin >> a; a--;
    g.add_edge(i,a);
    to[i] = a;
  }

  vector<ll> dp(n);
  for(auto v: g.scc()) {
    if (v.size() >= 2) for(int x: v) dp[x] = v.size();
  }

  auto rec = [&](auto self, int i) -> ll {
    if (dp[i] != 0) return dp[i];
    if (to[i] == i) return dp[i] = 1;
    return dp[i] = self(self,to[i]) + 1;
  };

  ll ans = 0;
  REP(i,n) ans += rec(rec,i);
  cout << ans << endl;
  return;
}

/* ========================= */

void solve2(int n) {
  vector g(n,vector<int>()), gr(n,vector<int>());
  REP(i,n) {
    int a; cin >> a; a--;
    g[i].push_back(a);
    gr[a].push_back(i);
  }

  vector<int> visited1(n);
  vector<int> finished;
  auto dfs1 = [&](auto self, int i) -> void {
    if (visited1[i] == 1) return;
    visited1[i] = 1;
    for(auto v: g[i]) {
      if (v == i) continue;
      self(self, v);
    }
    finished.push_back(i);
  };

  vector<int> visited2(n);
  auto dfs2 = [&](auto self, int i, vector<int>& res) -> void {
    if (visited2[i] == 1) return;
    visited2[i] = 1;
    res.push_back(i);
    for(auto v: gr[i]) {
      if (v == i) continue;
      self(self,v,res);
    }
  };

  REP(i,n) dfs1(dfs1,i);
  reverse(finished.begin(),finished.end());

  vector<vector<int>> cycles;
  for(auto i: finished) {
    vector<int> res;
    dfs2(dfs2,i,res);
    cycles.push_back(res);
  }

  vector<ll> dp(n);
  for(auto cycle: cycles) {
    if (cycle.size() >= 2) for(auto v: cycle) dp[v] = cycle.size();
  }

  auto rec = [&](auto self, int i) {
    if (dp[i] != 0) return dp[i];
    if (g[i][0] == i) return dp[i] = 1LL;
    return dp[i] = self(self,g[i][0]) + 1;
  };

  ll ans = 0;
  REP(i,n) ans += rec(rec,i);
  cout << ans << endl;
}

int main() {
  int n; cin >> n;
  solve1(n);
  // solve2(n);
  return 0;
}