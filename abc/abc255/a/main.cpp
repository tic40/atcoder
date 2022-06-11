#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)

int a[2][2];
int main() {
  int r,c; cin >> r >> c;
  r--; c--;
  REP(i,2) REP(j,2) cin >> a[i][j];
  cout << a[r][c] << endl;
  return 0;
}