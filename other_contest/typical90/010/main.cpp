#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'

int main() {
  int n; cin >> n;
  vector vp(2,vector<int>(n));
  REP(i,n) {
    int c,p; cin >> c >> p;
    c--;
    vp[c][i] = p;
  }
  vector m(2,vector<int>(n+1));
  REP(i,n) {
    m[0][i+1] = m[0][i] + vp[0][i];
    m[1][i+1] = m[1][i] + vp[1][i];
  }

  int q; cin >> q;
  REP(_,q) {
    int l,r; cin >> l >> r;
    l--;
    printf("%d %d\n", m[0][r] - m[0][l], m[1][r] - m[1][l]);
  }
  return 0;
}