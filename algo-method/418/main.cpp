#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(int)(n);i++)
#define ALL(x) x.begin(), x.end()
using ll = long long;
const int INF = 1e9;
const ll LINF = 1e18;
const int MOD = 1e9+7;

int n,m;
vector<vector<int>> g(10000);
vector<int> dist(10000, INF);

void bfs() {
  queue<int> q;
  q.push(0);
  dist[0] = 0;
  while(q.size()) {
    int cur = q.front();
    q.pop();
    int nd = dist[cur]+1;
    for (int v: g[cur]) {
      if (nd < dist[v]) {
        dist[v] = nd;
        q.push(v);
      }
    }
  }
  return;
}

void dfs(int i, int d) {
  dist[i] = d;
  int nd = d+1;
  for(int v: g[i]) {
    if (nd < dist[v]) {
      dfs(v, nd);
    }
  }
  return;
}

int main() {
  cin >> n >> m;
  REP(i,m) {
    int a,b;
    cin >> a >> b;
    g[a].push_back(b);
    g[b].push_back(a);
  }

  bfs();
  int ans = 0;
  REP(i,n) ans = max(ans, dist[i]);
  cout << ans << endl;

  return 0;
}