#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)

int main() {
  int r,c,k,ans=0;
  cin>>r>>c>>k;
  string s[r];
  int up[r+1][c+1],down[r+1][c+1];
  REP(i,r+1) REP(j,c+1) { up[i][j] = 0; down[i][j] = 0; }

  REP(i,r) cin>>s[i];
  REP(j,c) {
    REP(i,r) {
      if (s[i][j] == 'o') up[i][j] = i == 0 ? 1 : up[i-1][j] + 1;
      else up[i][j] = 0;
    }
    REPR(i, r-1) {
      if (s[i][j] == 'o') down[i][j] = down[i+1][j] + 1;
      else down[i][j] = 0;
    }
  }

  REP(i,r) {
    REP(j,c) {
      int ok = 0, left = j - (k - 1), right = j + k - 1;
      if (left < 0 || right > c) continue;

      for (int _j = left; _j <= right; _j++) {
        int diff = k - abs(j - _j);
        ok = up[i][_j] >= diff && down[i][_j] >= diff;
        if (!ok) break;
      }
      ans += ok;
    }
  }
  cout << ans << endl;
}