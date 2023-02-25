#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int n,m;
vector g(1e5,vector<int>());
vector<int> ans;
vector<bool> visited(1e5);

bool dfs(int i) {
  if (i == n-1) {
    ans.push_back(i);
    return true;
  }

  for(int v: g[i]) {
    if (visited[v]) continue;
    visited[v] = true;
    if (dfs(v)) {
      ans.push_back(i);
      return true;
    }
    visited[v] = false;
  }
  return false;
}

int main() {
  cin >> n >> m;
  REP(i,m) {
    int a,b; cin >> a >> b;
    a--; b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }

  dfs(0);
  reverse(ans.begin(),ans.end());
  for(int v: ans) cout << v+1 << " ";

  return 0;
}