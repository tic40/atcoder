#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<(int)(n);i++)
using ll = long long;
const int INF = 1e9;
const ll LINF = 1e18;
const int MOD = 1e9+7;

/*
  単純連結無向グラフとは、単純かつ連結で辺に向きの無いグラフのことをいいます。
  グラフが単純であるとは、グラフが自己ループや多重辺を含まないことをいいます。
  グラフが連結であるとは、グラフ上の任意の 2 頂点 s,t について s から t へ辺をたどって行けることをいいます。
  頂点 s と頂点 t の間の距離とは、頂点 s と頂点 t の間の最短路の長さのことをいいます。
*/
using Edge = struct { int to; ll cost; };

int n,m;
vector<vector<Edge>> g;
vector<ll> visited;
vector<int> A,B,C;
int target;

void dfs(int cur, ll cost = 0) {
  if (cur == target) return;

  for(auto [nto, ncost]: g[cur]) {
    if (cost + ncost < visited[nto]) {
      visited[nto] = cost + ncost;
      dfs(nto, ncost+cost);
    }
  }

  return;
}

void solve() {
  int ans = 0;
  REP(i,m) {
    int from = A[i];
    int to = B[i];
    int cost = C[i];

    visited = vector<ll>(n);
    REP(j,n) visited[j] = LINF;
    visited[from] = 0;

    target = to;
    dfs(from);
    if (visited[to] < cost) {
      // cout << from << " " << visited[to] << " " << cost << endl;
      ans++;
    }
  }

  cout << ans << endl;
  return;
}

int main() {
  cin >> n >> m;
  g.resize(n);
  A.resize(m);
  B.resize(m);
  C.resize(m);
  REP(i,m) {
    int a,b,c;
    cin >> a >> b >> c;
    a--; b--;
    g[a].emplace_back(Edge{b,c});
    g[b].emplace_back(Edge{a,c});
    A[i] = a;
    B[i] = b;
    C[i] = c;
  }

  solve();
  return 0;
}