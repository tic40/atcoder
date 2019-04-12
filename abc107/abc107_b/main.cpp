// https://atcoder.jp/contests/abc107/tasks/abc107_b
#include <bits/stdc++.h>
using namespace std;

int main() {
  int h, w;
  cin >> h >> w;
  vector<int> delRow(h, 0), delCol(w, 0);
  vector<vector<char>> data(h, vector<char>(w));
  char BLACK = '#';

  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      cin >> data.at(i).at(j);
    }
  }

  for (int i= 0; i < h; i++) {
    bool sameRow = true;
    for (int j = 0; j < w; j++) {
      if (
        data.at(i).at(j) == BLACK ||
        j > 0 && data.at(i).at(j-1) != data.at(i).at(j)
      ) {
        sameRow = false;
        break;
      }
    }
    if (sameRow) delRow.at(i) = 1;
  }

  for (int i= 0; i < w; i++) {
    bool sameColumn = true;
    for (int j = 0; j < h; j++) {
      if (
        data.at(j).at(i) == BLACK ||
        j > 0 && data.at(j-1).at(i) != data.at(j).at(i)
      ) {
        sameColumn = false;
        break;
      }
    }
    if (sameColumn) delCol.at(i) = 1;
  }

  for (int i = 0; i < h; i++) {
    if (delRow.at(i) == 1) continue;
    for (int j = 0; j < w; j++) {
      if (delCol.at(j) == 1) continue;
      cout << data.at(i).at(j);
    }
    cout << endl;
  }
}
