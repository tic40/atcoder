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

  scc_graph g(n);
  REP(i,m) {
    int a,b;
    cin >> a >> b;
    g.add_edge(a,b);
  }

  auto scc = g.scc();
  cout << scc.size() << endl;

  for (auto v: scc) {
    cout << v.size();
    for (auto x: v) cout << " " << x;
    cout << endl;
  }
}