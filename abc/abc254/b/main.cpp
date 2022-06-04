#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)

int main() {
  int n; cin >> n;
  vector<vector<int>> g(n);
  REP(i,n) REP(j,i+1) {
    if (j == 0 || j == i) g[i].push_back(1);
    else g[i].push_back( g[i-1][j-1] + g[i-1][j] );
  }

  REP(i,n) {
    for(int v: g[i]) cout << v << " ";
    cout << endl;
  }

  return 0;
}