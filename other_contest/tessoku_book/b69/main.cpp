#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n,m; cin >> n >> m;
  vector<string> c(n);
  REP(i,n) cin >> c[i];

  mf_graph<int> g(n+26);
  REP(i,n) REP(j,24) {
    if (c[i][j] == '1') g.add_edge(i,n+j,1);
  }

  REP(i,n) g.add_edge(n+24,i,10);
  REP(i,24) g.add_edge(n+i,n+25,m);

  int v = g.flow(n+24,n+25);
  cout << (v == 24*m ? "Yes" : "No") << endl;
  return 0;
}