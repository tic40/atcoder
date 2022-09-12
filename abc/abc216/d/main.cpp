#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'

int main() {
  int n,m; cin >> n >> m;
  vector<queue<int>> g(m);
  REP(i,m) {
    int k; cin >> k;
    REP(j,k) {
      int a; cin >> a;
      a--;
      g[i].push(a);
    }
  }

  vector<vector<int>> col(n);
  queue<int> q;
  REP(i,m) q.push(i);

  while(q.size()) {
    int i = q.front(); q.pop();
    if (g[i].empty()) continue;

    int v = g[i].front(); g[i].pop();
    col[v].push_back(i);

    if (col[v].size() == 2) {
      q.push(col[v][0]);
      q.push(i);
    }
  }

  bool ok = true;
  REP(i,m) if (g[i].size()) ok = false;
  cout << (ok ? "Yes" : "No") << endl;
  return 0;
}