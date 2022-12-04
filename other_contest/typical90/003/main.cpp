#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'

vector<vector<int>> g(1e5);
vector<int> d(1e5);

void dfs(int i, int p) {
  for(int v: g[i]) {
    if (v == p) continue;
    d[v] = d[i]+1;
    dfs(v,i);
  }
  return;
}

int main() {
  int n; cin >> n;
  REP(i,n-1) {
    int a,b; cin >> a >> b;
    a--; b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }

  // 0を根としてdfs
  dfs(0,-1);
  // 最も深いindexを取得
  int find = max_element(d.begin(),d.end()) - d.begin();
  d = vector<int>(n);
  // 最も深いindexを根としてdfs
  dfs(idx,-1);
  cout << *max_element(d.begin(),d.end())+1 << endl;
  return 0;
}