#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using P = pair<int,int>;
const int INF = numeric_limits<int>::max();

struct Edge {
  int to,cost,t;
  Edge(int to, int cost, int t): to(to),cost(cost),t(t) {}
};

int main() {
  int n,d; cin >> n >> d;
  vector g(n,vector<Edge>());
  REP(i,n-1) {
    int a,b,c; cin >> a >> b >> c;
    a--; b--;
    g[a].emplace_back(b,c,1);
    g[b].emplace_back(a,c,0);
  }

  // dist[i] := 頂点 0 を根としたときの i の部分木の中で最大の距離
  vector<int> dist(n);
  // weight[i] := 頂点 0 を根としたときの i の部分木の通行方向の変更回数の総和
  vector<int> weight(n);

  auto dfs1 = [&](auto self, int i, int p) -> void {
    for(auto [to,c,t]: g[i]) {
      if (to == p) continue;
      self(self,to,i);
      dist[i] = max(dist[i],dist[to]+c);
      weight[i] += weight[to] + t;
    }
  };

  auto dfs2 = [&](auto self, int i, int d_par, int d_weight, int p) -> int {
    vector<P> d_child;
    int latte = 0; // p を根としたときの通行方向の変更回数
    d_child.emplace_back(0,-1);
    for(auto [to,c,t]: g[i]) {
      if (to == p) {
        d_child.emplace_back(d_par+c, to);
        latte += d_weight + t;
      } else {
        d_child.emplace_back(dist[to]+c, to);
        latte += weight[to] + t;
      }
    }
    // d_child から dist が最大のものを取り出すために降順ソート
    sort(d_child.rbegin(),d_child.rend());

    int res = INF;
    if (d_child[0].first <= d) res = min(res,latte);

    for(auto [to,c,t]: g[i]) {
      if (to == p) continue;
      res = min(
        res,
        // d_par
        //  親の距離
        //  (d_child[d_child[0].second == to].first) := to(次の部分木の頂点)が
        //  dist が最も大きい部分木と同じであればその距離を d_par に指定する。
        //  そうでないときは 2 番目に大きい部分木の距離を d_par に指定する。
        // d_weight
        //  親の進行方向の変更回数
        self(self, to, d_child[d_child[0].second == to].first, latte - weight[to] - t, i)
      );
    }
    return res;
  };

  dfs1(dfs1,0,-1);
  int res = dfs2(dfs2,0,0,0,-1);
  cout << (res == INF ? -1 : res) << endl;
  return 0;
}