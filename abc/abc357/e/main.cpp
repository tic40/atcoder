#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;

int main() {
  int n; cin >> n;
  vector<int> to(n);
  vector rg(n,vector<int>());
  REP(i,n) {
    int a; cin >> a; a--;
    to[i] = a;
    rg[a].push_back(i);
  }

  vector<int> visited(n), visited2(n), order;
  auto dfs = [&](auto self, int i) -> void {
    if (visited[i]) return;
    visited[i] = 1;
    self(self,to[i]);
    order.push_back(i);
  };

  auto rdfs = [&](auto self, int i, vector<int>& cycle) -> void {
    if (visited2[i]) return;
    visited2[i] = 1;
    cycle.push_back(i);
    for(auto v: rg[i]) self(self,v,cycle);
  };

  REP(i,n) dfs(dfs,i);
  reverse(order.begin(),order.end());
  vector<vector<int>> cycles;
  for(int i: order) {
    vector<int> cycle;
    rdfs(rdfs,i,cycle);
    cycles.push_back(cycle);
  }

  vector<ll> dp(n);
  for(auto cycle: cycles) {
    if (cycle.size() == 1) continue;
    for(auto v: cycle) dp[v] = cycle.size();
  }

  auto rec = [&](auto self, int i) -> ll {
    if (dp[i] > 0) return dp[i];
    if (to[i] == i) return dp[i] = 1LL;
    return dp[i] = self(self,to[i]) + 1;
  };

  ll ans = 0;
  REP(i,n) ans += rec(rec,i);
  cout << ans << endl;
  return 0;
}