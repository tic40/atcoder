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
  REP(bith, 1<<h1) {
    if (__builtin_popcount(bith) != h2) continue;
    REP(bitw,1<<w1) {
      if (__builtin_popcount(bitw) != w2) continue;
      vector<int> is,js;
      REP(i,h1) if (bith >> i & 1) is.push_back(i);
      REP(j,w1) if (bitw >> j & 1) js.push_back(j);
      vector c(h2, vector<int>(w2));
      REP(i,h2) REP(j,w2) c[i][j] = a[is[i]][js[j]];

      if (b == c) ok = true;
    }
  }

  cout << (ok ? "Yes" : "No") << endl;
  return 0;
}