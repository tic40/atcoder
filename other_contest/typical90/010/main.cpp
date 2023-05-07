#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'

int main() {
  int n; cin >> n;
  vector a(2,vector<int>(n));
  vector m(2,vector<int>(n+1));
  REP(i,n) {
    int c,p; cin >> c >> p;
    c--;
    a[c][i] = p;
  }

  REP(i,2) REP(j,n) m[i][j+1] = m[i][j] + a[i][j];
  int q; cin >> q;
  REP(_,q) {
    int l,r; cin >> l >> r;
    l--;
    printf("%d %d\n", m[0][r]-m[0][l], m[1][r]-m[1][l]);
  }
  return 0;
}