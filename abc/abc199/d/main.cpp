#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'
using ll = long long;

vector<vector<int>> g(20);
vector<bool> visited(20);
vector<int> vs;
vector<int> col(20,-1);

vector<int> dfs(int i) {
  if (visited[i]) return {};

  vector<int> res = { i };
  visited[i] = true;

  for(int v: g[i]) {
    auto d = dfs(v);
    for(int t: d) res.push_back(t);
  }

  return res;
}

int dfs2(int i) {
  int res = 0;
  if (i == (int)vs.size()) return 1;

  int now = vs[i];
  REP(c,3) {
    col[now] = c;
    bool ok = true;
    for(int v: g[now]) if (c == col[v]) ok = false;

    if (ok) res += dfs2(i+1);
    col[now] = -1;
  }
  return res;
}

int main() {
  int n,m; cin >> n >> m;
  REP(i,m) {
    int a,b; cin >> a >> b;
    a--; b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }

  ll ans = 1;
  REP(i,n) {
    vs = dfs(i);
    if (vs.empty()) continue;

    col[vs[0]] = 0;
    ans *= 3LL * dfs2(1);
  }

  cout << ans << endl;
  return 0;
}