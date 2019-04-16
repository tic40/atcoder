// https://abs.contest.atcoder.jp/tasks/abc087_b
#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b, c, x;
  int total, count = 0;
  cin >> a >> b >> c >> x;
  for (int i = 0; i <= a; i++) {
    total = 0;
    for (int j = 0; j <= b; j++) {
      for (int k = 0; k <= c; k++) if ( (500 * i + 100 * j + 50 * k) == x ) count++;
    }
  }
  cout << count << endl;
}