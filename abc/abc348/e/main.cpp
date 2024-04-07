#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;

int main() {
  int n; cin >> n;
  vector g(n,vector<int>());
  REP(i,n-1) {
    int a,b; cin >> a >> b;
    a--; b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  vector<int> c(n);
  REP(i,n) cin >> c[i];

  // c の合計
  ll tot = accumulate(c.begin(),c.end(),0LL);
  // x: 木の重心となる頂点
  int x =  -1;
  {
    auto dfs = [&](auto self, int i, int p = -1) -> ll {
      ll res = c[i];
      ll mx = 0;
      for(auto v: g[i]) {
        if (v == p) continue;
        ll now = self(self,v,i);
        mx = max(mx,now);
        res += now;
      }
      // tot - res は親の部分木分
      mx = max(mx,tot-res);
      // どの部分木も 1/2 * tot 以下である
      if (mx * 2 <= tot) x = i;
      return res;
    };
    dfs(dfs,0);
  }

  ll ans = 0;
  auto dfs = [&](auto self, int i, int dist = 0, int p = -1) -> void {
    ans += (ll)dist * c[i];
    for(auto v: g[i]) {
      if (v == p) continue;
      self(self,v,dist+1,i);
    }
  };

  dfs(dfs,x);
  cout << ans << endl;
  return 0;
}