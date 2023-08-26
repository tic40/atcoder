#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;
using P = pair<int,int>;

int main() {
  int n,m; cin >> n >> m;
  vector g(n,vector<P>());
  REP(i,m) {
    int a,b,c; cin >> a >> b >> c;
    a--; b--;
    g[a].emplace_back(b,c);
    g[b].emplace_back(a,c);
  }

  auto dfs = [&](auto self, int i, int bit, ll now) -> ll {
    ll res = now;
    for(auto [to,cost]: g[i]) {
      if (bit & (1<<to)) continue;
      int nbit = bit | (1<<to);
      int ncost = now + cost;
      res = max(res,self(self,to,nbit,ncost));
    }
    return res;
  };

  ll ans = 0;
  REP(i,n) ans = max(ans,dfs(dfs,i,1<<i,0));
  cout << ans << endl;
  return 0;
}