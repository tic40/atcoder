#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<(int)(n);i++)
using ll = long long;
const int INF = 1e9;
const ll LINF = 1e18;
const int MOD = 1e9+7;

int main() {
  int n,m;
  cin >> n >> m;

  vector<vector<int>> g(n);
  dsu d(n);
  bool ok = true;

  REP(i,m) {
    int a,b; cin >> a >> b;
    a--; b--;
    g[a].push_back(b);
    g[b].push_back(a);

    if (d.leader(a) == d.leader(b)) ok = false;
    d.merge(a,b);
  }

  REP(i,n) if (2 < g[i].size()) ok = false;

  cout << (ok ? "Yes" : "No") << endl;
  return 0;
}