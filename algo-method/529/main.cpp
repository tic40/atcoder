#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(int)(n);i++)
#define ALL(x) x.begin(), x.end()
using ll = long long;
const int INF = 1e9;
const ll LINF = 1e18;
const int MOD = 1e9+7;

int n;
vector<vector<int>> g;
vector<int> d;

void dfs(int pos = 0, int pv = -1, int depth = 0) {
  d[pos] = depth;
  for(int v: g[pos]) {
    if (v == pv) continue;
    dfs(v, pos, depth+1);
  }
  return;
}

int main() {
  cin >> n;
  g.resize(n);
  d.resize(n);
  REP(i,n-1) {
    int p; cin >> p;
    g[p].push_back(i+1);
  }

  dfs();
  for(int v: d) cout << v << endl;
  return 0;
}