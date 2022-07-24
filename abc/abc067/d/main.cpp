#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'
const int INF = numeric_limits<int>::max();

vector<vector<int>> g(100001);
vector<vector<int>> dist(2,vector<int>(100001, INF));

void dfs(int i, int p, int id) {
  for(int v: g[i]) {
    if (v == p) continue;
    dist[id][v] = dist[id][i] + 1;
    dfs(v,i,id);
  }
  return;
}


int main() {
  int n; cin >> n;
  REP(i,n-1) {
    int a,b; cin >> a >> b;
    a--; b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }

  dist[0][0] = dist[1][n-1] = 0;
  dfs(0,-1,0);
  dfs(n-1,-1,1);

  int cnt = 0;
  REP(i,n) dist[0][i] <= dist[1][i] ? cnt++ : cnt--;

  cout << (cnt > 0 ? "Fennec" : "Snuke") << endl;
  return 0;
}