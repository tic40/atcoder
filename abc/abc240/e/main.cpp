#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<(int)(n);i++)
const int INF = 1e9;
using P = pair<int,int>;

vector<vector<int>> g;
vector<P> memo;
int id = 1;

P dfs(int cur, int prev) {
  int l = INF, r = -INF;
  bool isLeaf = true;

  for(int v: g[cur]) {
    if (v == prev) continue;
    isLeaf = false;
    auto [nl, nr] = dfs(v,cur);
    l = min(l,nl);
    r = max(r,nr);
  }

  if (isLeaf) l = r = id++;
  return memo[cur] = { l, r };
}

int main() {
  int n; cin >> n;
  g.resize(n);
  REP(i,n-1) {
    int u,v;
    cin >> u >> v;
    u--; v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  memo.resize(n);
  dfs(0,-1);
  REP(i,n) {
    auto [l,r] = memo[i];
    cout << l << " " << r << endl;
  }
  return 0;
}