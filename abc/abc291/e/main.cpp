#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n,m; cin >> n >> m;
  vector<vector<int>> g(n);
  vector<int> deg(n);
  REP(i,m) {
    int x,y; cin >> x >> y;
    x--; y--;
    g[x].push_back(y);
    deg[y]++;
  }

  queue<int> q;
  REP(i,n) if (deg[i] == 0) q.push(i);
  vector<int> ans(n);

  int now = 1;
  while(q.size()) {
    if (q.size() > 1) { cout << "No" << endl; return 0; }
    int v = q.front(); q.pop();
    ans[v] = now;
    now++;
    for(int nv: g[v]) {
      deg[nv]--;
      if (deg[nv] == 0) q.push(nv);
    }
  }

  cout << "Yes" << endl;
  for(int v: ans) cout << v << " ";
  return 0;
}