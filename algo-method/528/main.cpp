#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(int)(n);i++)

int n;
vector<vector<int>> g;

int dfs(int pos = 0, int pv = -1) {
  int res = 0;
  for (int v: g[pos]) {
    if (v == pv) continue;
    res = max(res, dfs(v, pos)+1);
  }
  return res;
}

int main() {
  cin >> n;
  g.resize(n);
  REP(i,n-1) {
    int p; cin >> p;
    g[p].push_back(i+1);
  }

  cout << dfs() << endl;
  return 0;
}