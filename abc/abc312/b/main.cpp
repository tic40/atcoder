#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n,m; cin >> n >> m;
  vector<string> s(n);
  REP(i,n) cin >> s[i];

  // 座標(x,y) から 3x3マスの領域がすべて黒 かつ 8方位隣接マスが全て白か？
  auto f = [&](int x, int y, vector<vector<int>> v) -> bool {
    REP(i,5) REP(j,5) {
      int nx = x-1+i, ny = y-1+j;
      if (nx < 0 || ny < 0 || nx >= 9 || ny >= 9) continue;
      // 3x3の外
      if (nx < x || ny < y || nx > x+2 || ny > y+2) {
        if (v[nx][ny] == '#')  return false;
      } else {
        if (v[nx][ny] == '.')  return false;
      }
    }
    return true;
  };

  REP(i,n-8) REP(j,m-8) {
    vector v(9, vector<int>(9));
    REP(k,9) REP(l,9) v[k][l] = s[i+k][j+l];
    if (f(0,0,v) && f(6,6,v)) cout << i+1 << " " << j+1 << endl;
  }
  return 0;
}