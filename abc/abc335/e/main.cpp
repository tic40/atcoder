#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;
using P = pair<int,int>;
const int INF = 1e9;

int main() {
  int n,m; cin >> n >> m;
  vector<int> a(n);
  REP(i,n) cin >> a[i];

  dsu uf(n);
  vector<P> edges;
  REP(i,m) {
    int u,v; cin >> u >> v;
    u--; v--;
    if (a[u] == a[v]) uf.merge(u,v);
    edges.emplace_back(u,v);
  }

  vector<vector<int>> to(n);
  for(auto [u,v]: edges) {
    u = uf.leader(u);
    v = uf.leader(v);
    if (u == v) continue;
    if (a[u] > a[v]) swap(u,v);
    to[u].push_back(v);
  }

  vector<int> vs;
  REP(i,n) if (uf.leader(i) == i) vs.push_back(i);
  sort(vs.begin(), vs.end(), [&](int u, int v) {
    return a[u] < a[v];
  });

  // dp[i] := i に来るまでのパスの最長
  vector<int> dp(n,-INF);
  dp[uf.leader(0)] = 1;
  for(int v: vs) {
    for(int u: to[v]) {
      dp[u] = max(dp[u], dp[v]+1);
    }
  }

  int ans = dp[uf.leader(n-1)];
  cout << (ans < 0 ? 0 : ans) << endl;
  return 0;
}