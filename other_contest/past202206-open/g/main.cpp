#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'

int main() {
  int n; cin >> n;
  vector<vector<int>> g(n);
  dsu uf(n);
  REP(i,n-1) {
    int a,b; cin >> a >> b;
    a--; b--;
    uf.merge(a,b);
  }

  cout << (uf.size(0) == n ? "Yes" : "No") << endl;
  return 0;
}