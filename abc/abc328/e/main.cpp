#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;
const ll LINF = numeric_limits<ll>::max();

int main() {
  int n,m; ll k; cin >> n >> m >> k;
  vector<int> u(m),v(m);
  vector<ll> w(m);
  REP(i,m) {
    cin >> u[i] >> v[i] >> w[i];
    u[i]--; v[i]--;
  }

  ll ans = LINF;
  auto dfs = [&](auto self, int i, vector<int> s) -> void {
    if ((int)s.size() == n-1) {
      dsu d(n);
      ll cost = 0;
      for(auto ns: s) {
        d.merge(u[ns],v[ns]);
        cost += w[ns];
        cost %= k;
      }
      if (d.size(0) == n) ans = min(ans,cost);
      return;
    }
    if (i >= m) return;

    self(self,i+1,s);
    s.push_back(i);
    self(self,i+1,s);
  };

  dfs(dfs,0,vector<int>());
  cout << ans << endl;
  return 0;
}