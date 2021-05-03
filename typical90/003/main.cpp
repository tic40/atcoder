#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)

int n;
vector<vector<int>> g;

vector<int> dfs(int x) {
  queue<int> q;
  vector<int> d(n,-1);

  auto push = [&](int x, int prev) {
    if (d[x] != -1) return;
    q.push(x);
    d[x] = d[prev]+1;
  };
  push(x, x);

  while(q.size()) {
    int cur = q.front(); q.pop();
    for (int v: g[cur]) {
      push(v, cur);
    }
  }

  return d;
}

void solve() {
  vector<int> d = dfs(0);

  pair<int,int> pa = { 0, 0 };
  REP(i,n) {
    if (pa.second < d[i]) pa = make_pair(i, d[i]);
  }
  d = dfs(pa.first);

  pa = make_pair(0,0);
  REP(i,n) {
    if (pa.second < d[i]) pa = make_pair(i, d[i]);
  }

  cout << pa.second+1 << endl;
  return;
}

int main() {
  cin >> n;
  g.resize(n);
  int a,b;
  REP(i,n-1) {
    cin >> a >> b; a--; b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }

  solve();
  return 0;
}