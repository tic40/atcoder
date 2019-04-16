#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  cin >> S;
  int cnt = 1;

  for (int i = 0; i < S.size(); i++) {
    if (S.at(i) == '+') {
      cnt++;
    } else if (S.at(i) == '-') {
      cnt--;
    } else {
      // do nothing
    }
  }
  cout << cnt << endl;
}
