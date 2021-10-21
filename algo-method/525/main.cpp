#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(int)(n);i++)

int n;
vector<vector<int>> g;

void dfs(int pos, int pv = -1) {
  cout << pos << " ";
  for(auto v: g[pos]) {
    if (v != pv) dfs(v);
  }
  return;
}

int main() {
  cin >> n;
  g.resize(n);
  REP(i,n-1) {
    int p; cin >> p;
    g[p].push_back(i+1);
  }

  REP(i,n) sort(g[i].begin(), g[i].end());
  dfs(0);
  return 0;
}