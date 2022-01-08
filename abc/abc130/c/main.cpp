#include <bits/stdc++.h>
using namespace std;
int main() {
  int w, h, x, y;
  cin >> w >> h >> x >> y;
  double ans = double(w) * double(h) / 2;
  int ans2 = 2*x == w && 2*y == h;
  printf("%f %d\n", ans, ans2);
}