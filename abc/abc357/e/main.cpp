#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;

int main() {
  int n; cin >> n;
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
  return 0;
}