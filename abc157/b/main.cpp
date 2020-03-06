#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
  int a[3][3];
  REP(i,3) REP(j,3) cin >> a[i][j];
  int n; cin >> n;
  int b;
  REP(i,n) {
    cin >> b;
    REP(i,3) { REP(j,3) { if (a[i][j] == b) a[i][j] = 0; } }
  }

  int bingo = 0;
  REP(i,3) {
    if (a[i][0] == 0 && a[i][1] == 0 && a[i][2] == 0) bingo = 1;
    if (a[0][i] == 0 && a[1][i] == 0 && a[2][i] == 0) bingo = 1;
  }
  if (a[0][0] == 0 && a[1][1] == 0 && a[2][2] == 0) bingo = 1;
  if (a[2][0] == 0 && a[1][1] == 0 && a[0][2] == 0) bingo = 1;

  cout << (bingo ? "Yes" : "No") << endl;
  return 0;
}