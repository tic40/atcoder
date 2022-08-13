#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'

int main() {
  int h1,w1; cin >> h1 >> w1;
  vector a(h1,vector<int>(w1));
  REP(i,h1) REP(j,w1) cin >> a[i][j];

  int h2,w2; cin >> h2 >> w2;
  vector b(h2,vector<int>(w2));
  REP(i,h2) REP(j,w2) cin >> b[i][j];

  bool ok = false;
  for(int bith = 1; bith < (1<<h1); bith++) {
    int bithcnt = __builtin_popcount(bith);
    if (bithcnt != h2) continue;
    for(int bitw = 1; bitw < (1<<w1); bitw++) {
      int bitwcnt = __builtin_popcount(bitw);
      if (bitwcnt != w2) continue;

      vector cur(bithcnt, vector<int>(bitwcnt));
      int ni = 0;
      REP(i,h1) {
        if ((bith >> i & 1) == 0) continue;
        int nj = 0;
        REP(j,w1) {
          if ((bitw >> j & 1) == 0) continue;
          cur[ni][nj] = a[i][j];
          nj++;
        }
        ni++;
      }
      if (cur == b) ok = true;
    }
  }

  cout << (ok ? "Yes" : "No") << endl;
  return 0;
}