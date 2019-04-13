// https://atcoder.jp/contests/arc031/tasks/arc031_2
#include <bits/stdc++.h>
using namespace std;

bool isReachableAll(vector<vector<char>> data, vector<vector<bool>> checked) {
  for (int i = 0; i < data.size(); i++) {
    for (int j = 0; j < data.at(0).size(); j++) {
      if (data.at(i).at(j) == 'o') {
        if (!checked.at(i).at(j)) return false;
      }
    }
  }
  return true;
}

void fillIsland(vector<vector<char>> &data, vector<vector<bool>> &checked, int x, int y) {
  if (data.at(x).at(y) != 'o') return ;
  if (checked.at(x).at(y) == true) return ;

  vector<int> dataX, dataY;
  checked.at(x).at(y) = true;
  if (x-1 >= 0) {
    fillIsland(data, checked, x-1, y);
  }
  if (x+1 < data.size()) {
    fillIsland(data, checked, x+1 , y);
  }
  if (y-1 >= 0) {
    fillIsland(data, checked, x, y-1);
  }
  if (y+1 < data.at(0).size()) {
    fillIsland(data, checked, x, y+1);
  }
}

bool isOneIsland(vector<vector<char>> &data, vector<vector<bool>> &checked, int x, int y) {
  fillIsland(data, checked, x, y);
  return isReachableAll(data, checked);
}

int main() {
  int SIZE = 10;
  vector<vector<char>> data(SIZE, vector<char>(SIZE));
  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j < SIZE; j++) {
      cin >> data.at(i).at(j);
    }
  }
  int x, y;
  for (int i = 0; i < SIZE && !x; i++) {
    for (int j = 0; j < SIZE && !y; j++) {
      if (data.at(i).at(j) == 'o') {
        x = i;
        y = j;
      }
    }
  }

  vector<vector<bool>> checked(SIZE, vector<bool>(SIZE, false));
  if (isOneIsland(data, checked, x, y)) {
    cout << "YES" << endl;
    return 0;
  }

  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j < SIZE; j++) {
      if (data.at(i).at(j) != 'o') {
        data.at(i).at(j) = 'o';
        vector<vector<bool>> tmpChecked(SIZE, vector<bool>(SIZE, false));
        if(isOneIsland(data, tmpChecked, i, j)) {
          cout << "YES" << endl;
          return 0;
        }
        data.at(i).at(j) = 'x';
      }
    }
  }
  cout << "NO" << endl;
  return 0;
}
