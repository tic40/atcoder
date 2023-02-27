#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n; cin >> n;
  vector<string> c(n);
  REP(i,n) cin >> c[i];

  mf_graph<int> g(n*2+2);
  REP(i,n) REP(j,n) {
    if (c[i][j] == '#') g.add_edge(i,n+j,1);
  }

  REP(i,n) {
    g.add_edge(2*n, i, 1);
    g.add_edge(n+i, 2*n+1, 1);
  }

  cout << g.flow(2*n,2*n+1) << endl;
  return 0;
}