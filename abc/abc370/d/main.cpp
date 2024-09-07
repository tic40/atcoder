#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int h,w,q; cin >> h >> w >> q;
  vector<set<int>> row_walls(h);
  vector<set<int>> col_walls(w);

  REP(i,h) REP(j,w) {
    row_walls[i].insert(j);
    col_walls[j].insert(i);
  }
  // 番兵
  REP(i,h) {
    row_walls[i].insert(-1);
    row_walls[i].insert(1e9);
  }
  REP(i,w) {
    col_walls[i].insert(-1);
    col_walls[i].insert(1e9);
  }

  int ans = h*w;
  auto del_wall = [&](int r, int c) -> void {
    if (r < 0 || r >= h || c < 0 || c >= w) return;
    row_walls[r].erase(row_walls[r].find(c));
    col_walls[c].erase(col_walls[c].find(r));
    ans--;
  };

  REP(_,q) {
    int r,c; cin >> r >> c; r--; c--;
    if (row_walls[r].count(c)) { del_wall(r, c); continue; }

    auto it_up = col_walls[c].lower_bound(r);
    auto it_down = it_up;
    auto it_left= row_walls[r].lower_bound(c);
    auto it_right = it_left;
    it_up--;
    it_left--;

    del_wall(*it_up, c);
    del_wall(*it_down, c);
    del_wall(r, *it_left);
    del_wall(r, *it_right);
  }

  cout << ans << endl;
  return 0;
}