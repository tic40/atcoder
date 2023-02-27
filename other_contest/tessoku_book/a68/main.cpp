#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n,m; cin >> n >> m;
  mf_graph<int> g(n);
  REP(i,m) {
    int a,b,c; cin >> a >> b >> c;
    a--; b--;
    g.add_edge(a,b,c);
  }
  cout << g.flow(0, n-1) << endl;
  return 0;
}