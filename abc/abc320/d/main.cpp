#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;
using P = pair<int,pair<ll,ll>>;

int main() {
  int n,m; cin >> n >> m;
  vector<int> a(m),b(m);
  vector<ll> x(m),y(m);
  vector g(n,vector<P>());

  REP(i,m) {
    cin >> a[i] >> b[i] >> x[i] >> y[i];
    a[i]--; b[i]--;
    g[a[i]].push_back({ b[i], {x[i],y[i]} });
    g[b[i]].push_back({ a[i], {-x[i],-y[i]} });
  }

  vector<pair<ll,ll>> ans(n);
  ans[0] = {0,0};
  vector<bool> visited(n);
  auto dfs = [&](auto self, int i) -> void {
    for(auto [v,pos]: g[i]) {
      if (visited[v]) continue;
      visited[v] = true;

      auto [nx,ny] = pos;
      auto [px,py] = ans[i];
      ans[v] = { px+nx, py+ny };
      self(self,v);
    }
  };
  visited[0] = true;
  dfs(dfs,0);

  REP(i,n) {
    if (!visited[i]) cout << "undecidable" << endl;
    else cout << ans[i].first << " " << ans[i].second << endl;
  }
  return 0;
}