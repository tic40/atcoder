#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)

int main() {
  int h,w,k;
  cin >> h >> w >> k;
  vector<string> c(h);
  REP(i,h) cin >> c[i];
  int bsum = 0;
  REP(i,h) REP(j,w) if (c[i][j] == '#') bsum++;

  int ans = 0;
  REP(bith, 1<<h) REP(bitw, 1<<w) {
    int now = bsum;
    vector<string> t = c;

    REP(i,h) {
      if ((bith >> i & 1) == 0) continue;
      REP(j,w) {
        if (t[i][j] == '#') now--;
        t[i][j] = '.';
      }
    }

    REP(i,w) {
      if ((bitw >> i & 1) == 0) continue;
      REP(j,h) {
        if (t[j][i] == '#') now--;
        t[j][i] = '.';
      }
    }
    if (now == k) ans++;
  }

  cout << ans << endl;
  return 0;
}