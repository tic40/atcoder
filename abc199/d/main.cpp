#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
using ll = long long;

int n,m;
vector<vector<int>> g;
vector<int> used,col,vs;
ll now;

void dfs(int v) {
  if (used[v]) return;
  used[v]=1;
  vs.push_back(v);

  for (int u: g[v]) dfs(u);
  return;
}

void dfs2(int i) {
  if (i == vs.size()) {
    now++;
    return;
  }
  int v = vs[i];
  REP(c,3) {
    col[v] = c;
    bool ok = true;
    for (int u: g[v]) {
      if (col[u] == c) ok = false;
    }
    if (!ok) continue;
    dfs2(i+1);
  }
  col[v] = -1;
  return;
}

void solve() {
  ll ans = 1;
  used.resize(n);
  col.resize(n,-1);
  REP(i,n) {
    if (used[i]) continue;
    ans*=3;
    vs = vector<int>();
    dfs(i);
    col[vs[0]] = 0;
    now = 0;
    dfs2(1);
    ans *= now;
  }

  cout << ans << endl;
  return;
}


int main() {
  cin >> n >> m;
  g.resize(n);
  REP(i,m) {
    int a,b;
    cin >> a >> b;
    a--; b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }

  solve();
  return 0;
}