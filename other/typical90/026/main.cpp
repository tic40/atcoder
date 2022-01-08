#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)

int n;
vector<vector<int>> g;

void solve() {
  vector<int> col(n, -1);
  queue<int> q;
  q.push(0);
  col[0]=0;

  vector<int> cnt(2);
  while(q.size()) {
    int v = q.front(); q.pop();

    for(int u: g[v]) {
      if (col[u] != -1) continue;
      q.push(u);
      col[u] = col[v]^1;
    }
  }

  vector<int> col1,col2;
  REP(i,n) {
    if (col[i] == 0) col1.push_back(i);
    else col2.push_back(i);
  }

  vector<int> ans = col1.size() <= col2.size() ? col2 : col1;
  REP(i,n/2) cout << ans[i]+1 << endl;

  return;
}

int main() {
  cin >> n;
  g.resize(n);
  REP(i,n-1) {
    int a,b;
    cin >> a >> b;
    a--; b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }

  solve();
  return 0;
}