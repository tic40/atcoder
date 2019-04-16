// https://abs.contest.atcoder.jp/tasks/arc089_a
#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, t, x, y;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> t >> x >> y;
    if ( t < (x + y) || (t % 2) != ((x + y) % 2)) {
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
}