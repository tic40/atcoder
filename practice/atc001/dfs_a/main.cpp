// https://atcoder.jp/contests/atc001/tasks/dfs_a
#include <bits/stdc++.h>
using namespace std;

void fillWay(vector<vector<char>> &data, vector<vector<bool>> &checked, int x, int y) {
  if (x < 0 || x >= data.size() || y < 0 || y >= data.at(0).size()) return;
  if (checked.at(x).at(y)) return;
  if (data.at(x).at(y) == '#') return;

  checked.at(x).at(y) = true;
  if (data.at(x).at(y) == 'g') return;

  for (int num : { -1, 1 }) {
    fillWay(data, checked, x+num, y);
    fillWay(data, checked, x, y+num);
  }
} 

int main() {
  int h, w;
  cin >> h >> w;
  vector<vector<char>> data(h, vector<char>(w));
  vector<vector<bool>> checked(h, vector<bool>(w, false));

  int sx, sy, gx, gy;
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      cin >> data.at(i).at(j);
      if (data.at(i).at(j) == 's') {
        sx = i; sy = j;
      } else if (data.at(i).at(j) == 'g') {
        gx = i; gy = j;
      } else { /* do nothing */ }
    }
  }

  fillWay(data, checked, sx, sy);
  checked.at(gx).at(gy) ? cout << "Yes" : cout << "No";
  cout << endl;
}