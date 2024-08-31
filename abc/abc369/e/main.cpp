#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;
const ll LINF = numeric_limits<ll>::max();

struct Bridge {
  int e1,e2;
  ll cost;
};

int main() {
  int n,m; cin >> n >> m;
  vector dp(n, vector<ll>(n,1e18));
  REP(i,n) dp[i][i] = 0;
  vector<Bridge> bridges;
  REP(i,m) {
    int u,v; ll t; cin >> u >> v >> t;
    u--; v--;
    dp[u][v] = min(dp[u][v],t);
    dp[v][u] = min(dp[v][u],t);
    bridges.emplace_back(u,v,t);
  }

  // ワーシャルフロイド
  REP(k,n) REP(i,n) REP(j,n) dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);

  int q; cin >> q;
  REP(_,q) {
    int k; cin >> k;
    vector<int> x(k);
    REP(i,k) { cin >> x[i]; x[i]--; }

    ll ans = LINF;
    vector<int> b(k);
    iota(b.begin(),b.end(),0);
    do {
      auto dfs = [&](auto self, int i, int now, ll tot) {
        if (i == k) return tot + dp[now][n-1];
        auto [e1,e2,cost] = bridges[x[b[i]]];
        return min(
          self(self, i+1, e1, tot+dp[now][e2] + cost),
          self(self, i+1, e2, tot+dp[now][e1] + cost)
        );
      };
      ans = min(ans,dfs(dfs,0,0,0));
    } while (next_permutation(b.begin(), b.end()));

    cout << ans << endl;
  }
  return 0;
}