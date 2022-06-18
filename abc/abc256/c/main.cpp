#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)

int main() {
  vector<int> h(3),w(3);
  REP(i,3) cin >> h[i];
  REP(i,3) cin >> w[i];

  int ans = 0;
  vector<vector<int>> a(3,vector<int> (3));
  for(int i1 = 1; i1 <= 30; i1++) {
    for(int i2 = 1; i2 <= 30; i2++) {
      for(int i3 = 1; i3 <= 30; i3++) {
        for(int i4 = 1; i4 <= 30; i4++) {

          a[0][0] = i1;
          a[0][1] = i2;
          a[1][0] = i3;
          a[1][1] = i4;

          a[0][2] = w[0] - (a[0][0] + a[0][1]);
          a[1][2] = w[1] - (a[1][0] + a[1][1]);

          a[2][0] = h[0] - (a[0][0] + a[1][0]);
          a[2][1] = h[1] - (a[0][1] + a[1][1]);
          a[2][2] = h[2] - (a[0][2] + a[1][2]);

          bool ok = true;
          REP(_i,3) REP(_j,3) if (a[_i][_j] <= 0) ok = false;
          if (a[2][2] != w[2] - (a[2][0] + a[2][1])) ok = false;

          if (ok) ans++;
        }
      }
    }
  }

  cout << ans << endl;
  return 0;
}
