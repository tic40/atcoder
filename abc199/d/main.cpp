#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
using ll = long long;

int n,m;
vector<vector<int>> g;
vector<int> used, col;
vector<int> vs;
int now;

void dfs(int v) {
  if (used[v]) return;

  used[v] = 1;
  vs.push_back(v);
  for(int u: g[v]) dfs(u);
  return;
}

void dfs2(int i) {
  // 最後までたどり着いたらnow(通りの数)をインクリメントする
  if (i == vs.size()) {
    now++; return;
  }

  int v = vs[i];
  REP(c,3) {
    col[v] = c;
    bool ok = true;
    // 隣接する頂点の色が同じでないかどうか
    for (int u: g[v]) {
      if (col[u] == c) ok = false;
    }
    if (ok) dfs2(i+1);
  }
  // colを元に戻す
  col[v] = -1;
  return;
}

void solve() {
  used.resize(n);
  col.resize(n,-1);

  ll ans = 1;
  REP(i,n) {
    if (used[i]) continue;

    vs = vector<int>();
    dfs(i);
    now = 0;
    ans *= 3;
    col[vs[0]]=0;
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