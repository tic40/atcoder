#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m, y;
  cin >> n >> m;

  // 2x + 3y + 4(n - x - y) = m
  // y = 4n -2x - m
  for (int i = 0; i <= n; i++) {
    y = (4 * n) - (2 * i) - m;
    if (y < 0) continue;
    if (n < (y + i)) continue;
    cout << i << " " << y << " " << n - (y + i) << "\n";
    return 0;
  }
  cout << "-1 -1 -1" << "\n";
}