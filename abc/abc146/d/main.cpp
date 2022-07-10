#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
using P = pair<int,int>;

vector<vector<P>> g;
vector<int> col;

void dfs(int i, int p, int pcol) {
  int ncol = 1; // 今使える色
  for(auto [v, idx]: g[i]) {
    if (v == p) continue;
    if (ncol == pcol) ncol++; // 親で使った色と同じであれば++
    col[idx] = ncol;
    dfs(v, i, col[idx]);
    ncol++;
  }
  return;
}

int main() {
  int n; cin >> n;
  g.resize(n);
  REP(i,n-1) {
    int a,b; cin >> a >> b;
    a--; b--;
    g[a].emplace_back(b,i);
    g[b].emplace_back(a,i);
  }

  col.resize(n-1);
  dfs(0, -1, -1);

  int mx = *max_element(col.begin(), col.end());
  cout << mx << endl;
  for(int v: col) cout << v << endl;

  return 0;
}