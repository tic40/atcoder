#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)

int h,w;
int a[500][500];

int main() {
  cin >> h >> w;
  REP(i,h) REP(j,w) cin >> a[i][j];

  vector<vector<int>> ans;
  auto rec = [&](int y, int x, int ny, int nx) {
    if (h <= ny || w <= nx) return false;
    ans.push_back({ y, x, ny, nx });
    a[y][x]--;
    a[ny][nx]++;
    return true;
  };

  REP(i,h) REP(j,w) {
    // 偶数枚はスキップ
    if (a[i][j] % 2 == 0) continue;
    // 右方向に配る
    if (rec(i,j,i,j+1)) continue;
    // 下方向に配る
    rec(i,j,i+1,j);
  }

  // output
  cout << ans.size() << endl;
  for(auto v: ans) {
    REP(i,4) {
      if (i != 0) cout << " ";
      cout << v[i]+1;
    }
    cout << endl;
  }

  return 0;
}