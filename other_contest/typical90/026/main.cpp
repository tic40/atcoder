#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'

vector<int> dist(1e5);
vector<vector<int>> g(1e5);

void dfs(int i, int p) {
  for(int v: g[i]) {
    if (v == p) continue;
    dist[v] = dist[i]+1;
    dfs(v,i);
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

  dfs(0,-1);
  vector<int> odd,even;
  REP(i,n) {
    if (dist[i]%2) odd.push_back(i+1);
    else even.push_back(i+1);
  }

  vector<int> &ans = ((int)odd.size() >= n/2) ? odd : even;
  REP(i,n/2) cout << ans[i] << " ";
  return 0;
}