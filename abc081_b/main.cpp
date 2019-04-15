// https://abs.contest.atcoder.jp/tasks/abc081_b
#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n; i++) cin >> arr.at(i);

  int count = 0;
  bool loop = true;
  while(loop) {
    for (int i = 0; i < n; i++) {
      if (arr.at(i)%2 == 1) {
        loop = false;
        break;
      }
      arr.at(i) = arr.at(i) / 2;
    }
    if (loop) count++;
  }
  cout << count << endl;
}