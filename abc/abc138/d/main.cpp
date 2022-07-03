#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)

vector<vector<int>> g;
vector<int> c, ans;

void dfs(int i, int p) {
  if (p != -1) ans[i] += ans[p];
  ans[i] += c[i];

  for(int v: g[i]) {
    if (v == p) continue;
    dfs(v,i);
  }
  return;
}

int main() {
  int n,q; cin >> n >> q;
  g.resize(n);
  c.resize(n);
  ans.resize(n);

  REP(i,n-1) {
    int a,b; cin >> a >> b;
    a--; b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }

  REP(i,q) {
    int p,x; cin >> p >> x;
    p--;
    c[p] += x;
  }

  dfs(0, -1);
  for(int v : ans) cout << v << " ";
  cout << endl;

  return 0;
}