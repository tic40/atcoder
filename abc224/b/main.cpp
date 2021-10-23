#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(int)(n);i++)

int h,w;
int a[50][50];

int main() {
  cin >> h >> w;
  REP(i,h) REP(j,w) cin >> a[i][j];

  int ok = true;
  REP(i,h) {
    for( int i2 = i+1; i2 < h; i2++) {
      REP(j,w) {
        for( int j2 = j+1; j2 < w; j2++) {
          if (a[i][j] + a[i2][j2] <= a[i2][j] + a[i][j2]) continue;
          ok = false;
        }
      }
    }
  }

  cout << (ok ? "Yes" : "No") << endl;
  return 0;
}