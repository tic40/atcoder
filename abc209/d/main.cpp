#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
const int INF = 1e9;

int n,q;
vector<vector<int>> g;
vector<int> c,d;
vector<int> visited(100000, INF);

void dfs(int cur) {
  int nd = visited[cur] + 1;
  for(auto nv: g[cur]) {
    if (nd < visited[nv]) {
      visited[nv] = nd;
      dfs(nv);
    }
  }
  return;
}

void solve() {
  visited[0] = 0;
  dfs(0);
  REP(i,q) {
    int dist = abs(visited[c[i]] - visited[d[i]]);
    cout << ((dist % 2 == 0) ? "Town" : "Road") << endl;
  }
  return;
}

int main() {
  cin >> n >> q;
  g.resize(n);
  REP(i,n-1) {
    int a,b;
    cin >> a >> b;
    a--; b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }

  c.resize(q); d.resize(q);
  REP(i,q) {
    cin >> c[i] >> d[i];
    c[i]--; d[i]--;
  }

  solve();
  return 0;
}