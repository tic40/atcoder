#include <bits/stdc++.h>
using namespace std;

int main() {
  vector<int> data(5);
  bool hasSameNumber = false;
  for (int i = 0; i < 5; i++) {
    cin >> data.at(i);
  }

  for (int i = 1; i < data.size(); i++) {
    if (data.at(i) == data.at(i - 1)) {
      hasSameNumber = true;
      break;
    }
  }
  cout << (hasSameNumber ? "YES" : "NO") << endl;
}
