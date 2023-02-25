#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n,m; cin >> n >> m;
  dsu uf(n);
  REP(i,m) {
    int a,b; cin >> a >> b;
    a--; b--;
    uf.merge(a,b);
  }

  if (uf.size(0) == n) cout << "The graph is connected." << endl;
  else cout << "The graph is not connected." << endl;
  return 0;
}