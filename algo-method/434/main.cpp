#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(int)(n);i++)

int n;
vector<vector<int>> g;
vector<int> d;

int dfs(int pos = 0, int pv = -1) {
  int res = 1;
  for(int v: g[pos]) {
    if (v != pv) res += dfs(v, pos);
  }

  d[pos] = res;
  return res;
}

int main() {
  int n; cin >> n;
  g.resize(n);
  d.resize(n);
  REP(i,n-1) {
    int p; cin >> p;
    g[p].push_back(i+1);
  }

  dfs();
  for(int v: d) cout << v-1 << " ";
  return 0;
}