#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int r,c; cin >> r >> c;
  vector<string> b(r);
  REP(i,r) cin >> b[i];

  auto f = [&](int i, int j) {
    if (b[i][j] == '.' || b[i][j] == '#') return;
    int x = b[i][j]-'0';
    for(int k = max(0,i-x); k <= min(r-1,i+x); k++) {
      for(int l = max(0,j-x); l <= min(c-1,j+x); l++) {
        if (abs(i-k)+abs(j-l) <= x) if (b[k][l] == '#') b[k][l] = '.';
      }
    }
    b[i][j] = '.';
  };

  REP(i,r) REP(j,c) f(i,j);
  REP(i,r) {
    REP(j,c) cout << b[i][j];
    cout << endl;
  }
  return 0;
}