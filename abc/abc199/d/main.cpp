#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'
using ll = long long;

int n,m;
vector<vector<int>> g(20);
vector<bool> visited(20);
vector<int> col(20,-1);
vector<int> vs;

vector<int> dfs(int i) {
  vector<int> res;
  if (visited[i]) return res;
  visited[i] = true;

  res.push_back(i);
  for(int v: g[i]) {
    auto d = dfs(v);
    for(int t: d) res.push_back(t);
  }
  return res;
}

int dfs2(int i) {
  if (i == (int)vs.size()) return 1;

  int res = 0, v = vs[i];
  REP(c,3) {
    col[v] = c;
    bool ok = true;
    for(int u: g[v]) {
      if (col[u] == c) ok = false;
    }
    if (ok) res += dfs2(i+1);
  }
  col[v] = -1;
  return res;
}

int main() {
  cin >> n >> m;
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
    ans *= 3 * dfs2(1);
  }

  cout << ans << endl;
  return 0;
}