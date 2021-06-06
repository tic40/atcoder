#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)

int n,m;
vector<vector<int>> g;
vector<bool> visited;

void dfs(int cur) {
  if (visited[cur]) return;
  visited[cur] = true;
  for(auto v: g[cur]) dfs(v);
  return;
}

void solve() {
  int ans = 0;
  visited.resize(n);

  REP(i,n) {
    REP(j,n) visited[j] = false;
    dfs(i);
    REP(j,n) ans += visited[j] == true;
  }

  cout << ans << endl;
  return;
}

int main() {
  cin >> n >> m;
  g.resize(n);
  int a,b;
  REP(i,m) {
    cin >> a >> b;
    a--; b--;
    g[a].push_back(b);
  }
  solve();
  return 0;
}