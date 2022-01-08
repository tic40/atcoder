#include <bits/stdc++.h>
using namespace std;

int main() {
  int size = 4;
  vector<vector<char>> data(size, vector<char>(size));
  for(int i = 0; i < size; i++) {
    for(int j = 0; j < size; j++) {
      cin >> data.at(i).at(j);
    }
  }
  for(int i = size - 1; i >= 0; i--) {
    for(int j = size - 1; j >= 0; j--) {
      cout << data.at(i).at(j);
      if (j > 0) cout << " ";
    }
    cout << endl;
  }
}