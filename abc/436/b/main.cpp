#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n; cin >> n;
  vector g(n,vector<int>(n));

  int k = 1;
  int r = 0, c = (n-1)/2;
  auto f = [&](int i, int j) {
    if (g[i][j] == 0) { g[i][j] = k++; return 1; }
    return 0;
  };

  f(r,c);
  REP(i,n*n) {
    int nr = (r-1+n)%n, nc = (c+1)%n;
    if (!f(nr,nc)) {
      nr = (r+1)%n, nc = c;
      f(nr,nc);
    }
    r = nr; c = nc;
  }

  REP(i,n) {
    REP(j,n) cout << g[i][j] << " ";
    cout << endl;
  }
  return 0;
}
