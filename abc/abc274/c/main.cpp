#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'
const int INF = numeric_limits<int>::max();

int n;
vector<int> a(2e5);
vector<vector<int>> g(4e5+1);
vector<int> dist(4e5+1,INF);

void dfs(int i, int p) {
  for(int v: g[i]) {
    if (v == p) continue;
    dist[v] = dist[i]+1;
    dfs(v,i);
  }
  return;
}

int main() {
  cin >> n;
  REP(i,n) cin >> a[i];

  REP(i,n) {
    g[a[i]].push_back((i+1)*2);
    g[a[i]].push_back((i+1)*2+1);
  }

  dist[1] = 0;
  dfs(1,-1);

  for(int k = 1; k <= 2*n+1; k++) cout << dist[k] << endl;
  return 0;
}