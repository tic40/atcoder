#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'

int main() {
  int h,w; cin >> h >> w;
  vector s(h,vector<int>(w));
  REP(i,h) REP(j,w) cin >> s[i][j];

  int n; cin >> n;
  REP(i,n) {
    int r,c; cin >> r >> c;
    r--; c--;
    if (s[r][c] == 0) continue;
    s[r][c] = 0;

    r--;
    while(r >= 0 && s[r][c] != 0) {
      swap(s[r][c],s[r+1][c]);
      r--;
    }
  }

  REP(i,h) {
    REP(j,w) cout << s[i][j] << " ";
    cout << endl;
  }
  return 0;
}