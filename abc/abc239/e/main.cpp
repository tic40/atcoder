#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<(int)(n);i++)
using ll = long long;
const int INF = 1e9;
const ll LINF = 1e18;
const int MOD = 1e9+7;

vector<int> x;
vector<vector<int>> g,memo;

vector<int> dfs(int cur, int prev = -1) {
  vector<int> t = { x[cur] };
  for(int v: g[cur]) {
    if (v == prev) continue;
    for(int nv: dfs(v, cur)) {
      t.push_back(nv);
    }
  }
  sort(t.rbegin(), t.rend());
  vector<int> res;
  REP(i, min((int)t.size(), 20)) res.push_back(t[i]);
  return memo[cur] = res;
}

int main() {
  int n,q; cin >> n >> q;
  x.resize(n);
  REP(i,n) cin >> x[i];
  g.resize(n);
  memo.resize(n);

  REP(i,n-1) {
    int a,b; cin >> a >> b;
    a--; b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }

  dfs(0);

  REP(i,q) {
    int v,k; cin >> v >> k;
    v--; k--;
    cout << memo[v][k] << endl;
  }

  return 0;
}