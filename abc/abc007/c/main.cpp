#include <bits/stdc++.h>
using namespace std;

int main() {
  int r, c, sy, sx, gy, gx;
  char PATH = '.', WALL = '#';
  cin >> r >> c;
  cin >> sy >> sx;
  cin >> gy >> gx;
  sy -= 1; sx -= 1; gy -= 1; gx -= 1;
  vector<vector<char>> data(r, vector<char>(c));
  vector<vector<int>> visited(r, vector<int>(c, -1));
  vector<vector<int>> q;
  vector<vector<int>> moves = {
    { 1, 0 },
    { -1, 0 },
    { 0, 1 },
    { 0, -1 }
  };

  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) cin >> data.at(i).at(j);
  }

  q.push_back({sy, sx, 0});
  while (q.size() > 0) {
    vector<int> pos = q.front();
    int y = pos.at(0), x = pos.at(1), step = pos.at(2);
    q.erase(q.begin());
    if (y < 0 || y >= data.size() || x < 0 || x >= data.at(0).size()) continue;
    if (data.at(y).at(x) == WALL) continue;
    if (visited.at(y).at(x) != -1) continue;
    visited.at(y).at(x) = step;
    if (y == gy && x == gx) break;
    for (vector<int> move: moves) q.push_back({ y + move.at(0), x + move.at(1), step + 1 });
  }
  cout << visited.at(gy).at(gx) << "\n";
}