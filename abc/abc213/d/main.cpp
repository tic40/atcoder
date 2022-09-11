#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'

int n;
vector<vector<int>> g(2e5);
vector<int> ans;

void dfs(int i, int p) {
  ans.push_back(i);
  for(int v: g[i]) {
    if (v == p) continue;
    dfs(v,i);
    ans.push_back(i);
  }
  return;
}

int main() {
  cin >> n;
  REP(i,n-1) {
    int a,b; cin >> a >> b;
    a--; b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }

  for(auto& v: g) sort(v.begin(),v.end());
  dfs(0,-1);

  for(int v: ans) cout << v+1 << " ";
  return 0;
}