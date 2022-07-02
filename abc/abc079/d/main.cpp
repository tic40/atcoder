#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)

int main() {
  int h,w; cin >> h >> w;
  vector c(10, vector<int>(10));
  vector a(h, vector<int>(w));
  REP(i,10) REP(j,10) cin >> c[i][j];
  REP(i,h) REP(j,w) cin >> a[i][j];

  REP(k,10) REP(i,10) REP(j,10) {
    c[i][j] = min(c[i][j], c[i][k]+c[k][j]);
  }

  int ans = 0;
  REP(i,h) REP(j,w) if (a[i][j] != -1) ans += c[a[i][j]][1];
  cout << ans << endl;
  return 0;
}