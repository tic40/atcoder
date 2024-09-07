#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
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

  int ans = h*w;
  auto del_wall = [&](int r, int c) -> void {
    row_walls[r].erase(row_walls[r].find(c));
    col_walls[c].erase(col_walls[c].find(r));
    ans--;
  };

  REP(_,q) {
    int r,c; cin >> r >> c; r--; c--;
    if (row_walls[r].count(c)) { del_wall(r, c); continue; }

    auto it_up = col_walls[c].lower_bound(r);
    auto it_down = col_walls[c].upper_bound(r);
    auto it_left = row_walls[r].lower_bound(c);
    auto it_right = row_walls[r].upper_bound(c);

    if (it_up != col_walls[c].begin()) del_wall(*(--it_up), c);
    if (it_down != col_walls[c].end()) del_wall(*it_down, c);
    if (it_left != row_walls[r].begin()) del_wall(r, *(--it_left));
    if (it_right != row_walls[r].end()) del_wall(r, *it_right);
  }
  cout << ans << endl;
  return 0;
}