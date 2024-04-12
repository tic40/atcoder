#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;
const int INF = numeric_limits<int>::max();
const ll LINF = numeric_limits<ll>::max();

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

  // 解説放送解: 木の重心から解く
  auto solve1 = [&]() {
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
  };

  // 全方位木DP
  auto solve2 = [&]() {

    // sum_c[i] := 頂点 i の部分木 c の合計値
    vector<ll> sum_c(n);
    // sum_cd[i] := 頂点 i の各部分木への辺の数 * c の合計値
    vector<ll> sum_cd(n);
    auto dfs1 = [&](auto self,int i, int p) -> void {
      sum_c[i] = c[i];
      sum_cd[i] = 0;
      for(auto v: g[i]) {
        if (v == p) continue;
        self(self,v,i);
        sum_c[i] += sum_c[v];
        sum_cd[i] += sum_cd[v] + sum_c[v];
      }
    };

    ll ans = LINF;
    auto dfs2 = [&](auto self, int i, int p, ll p_sum_c, ll p_sum_cd) -> void {
      // 今いる頂点の答え
      ans = min(ans, p_sum_cd + sum_cd[i]);
      for(auto v: g[i]) {
        if (v == p) continue;
        ll np_sum_c = p_sum_c + sum_c[i] - sum_c[v];
        ll np_sum_cd = p_sum_cd + sum_cd[i] - sum_c[v] - sum_cd[v] + np_sum_c;
        self(self, v, i, np_sum_c, np_sum_cd);
      }
    };

    dfs1(dfs1,0,-1);
    dfs2(dfs2,0,-1,0,0);
    cout << ans << endl;
  };

  // solve1(); // 木の重心
  solve2(); // 全方位木DP
  return 0;
}