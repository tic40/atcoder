#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'

int main() {
  int n,m; cin >> n >> m;
  vector<vector<int>> g(n);
  REP(i,m) {
    int a,b; cin >> a >> b;
    a--; b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  REP(i,n) {
    sort(g[i].begin(),g[i].end());
    cout << g[i].size() << " ";
    for(auto v: g[i]) cout << v+1 << " ";
    cout << endl;
  }
  return 0;
}