#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
typedef long long ll;

bool graph[9][9];
int dfs(int v, int N, bool visited[]) {
  bool visited_all = true;
  REP(i,N+1) if (!visited[i]) visited_all = false;
  if (visited_all) return 1;

  int ret = 0;
  REP(i,N+1) {
    if (graph[v][i] == false) continue;
    if (visited[i]) continue;
    visited[i] = true;
    ret+=dfs(i,N,visited);
    visited[i] = false;
  }
  return ret;
}

int main() {
  int N,M; cin >> N >> M;
  bool visited[N+1];
  REP(i,N+1) visited[i] = false;
  visited[0] = true; // 0は存在しない
  visited[1] = true; // 1は始点

  int a,b;
  REP(i,M) {
    cin >> a >> b;
    graph[a][b] = true; graph[b][a] = true;
  }
  cout << dfs(1, N, visited) << endl;
}