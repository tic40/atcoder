#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(int)(n);i++)
#define ALL(x) x.begin(), x.end()
using ll = long long;
const int INF = 1e9;
const ll LINF = 1e18;
const int MOD = 1e9+7;

struct Edge {
  int to, cost;
};

int n,x;
vector<vector<Edge>> g;

bool dfs(int cur, int prev, ll dist) {
  if (dist == x) return true;

  int ok = false;
  for(auto [to, cost]: g[cur]) {
    if (to == prev) continue;
    if (dfs(to,cur,cost+dist)) ok = true;
  }

  return ok;
}

int main() {
  cin >> n >> x;
  g.resize(n);
  REP(i,n-1) {
    int a,b,c;
    cin >> a >> b >> c;
    a--,b--;
    g[a].push_back(Edge{b,c});
    g[b].push_back(Edge{a,c});
  }

  REP(i,n) {
    if (dfs(i,-1,0)) {
      cout << "Yes" << endl;
      return 0;
    }
  }

  cout << "No" << endl;
  return 0;
}