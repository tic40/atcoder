#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)

int n;
vector<vector<int>> g;

void dfs(int cur, int prev) {
  cout << cur+1 << " ";
  for(int v: g[cur]) {
    if (prev != v) {
      dfs(v,cur);
      cout << cur+1 << " ";
    }
  }
}

int main() {
  cin >> n;
  g.resize(n);
  REP(i,n-1) {
    int a,b; cin >> a >> b;
    a--; b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }

  for(auto& v: g) sort(v.begin(), v.end());
  dfs(0,-1);
  cout << endl;
  return 0;
}