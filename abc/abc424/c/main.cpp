#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n; cin >> n;
  vector g(n,vector<int>());
  queue<int> q;
  REP(i,n) {
    int a,b; cin >> a >> b; a--; b--;
    if (a == -1 && b == -1) { q.push(i); continue; }

    g[a].push_back(i);
    g[b].push_back(i);
  }

  vector<int> visited(n);
  while(q.size()) {
    auto i = q.front(); q.pop();
    if (visited[i]) continue;
    visited[i] = 1;
    for(auto v: g[i]) q.push(v);
  }
  cout << accumulate(visited.begin(),visited.end(),0) << endl;
  return 0;
}