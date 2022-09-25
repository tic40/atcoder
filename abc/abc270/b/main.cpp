#include <bits/stdc++.h>
using namespace std;

int main() {
  int x,y,z; cin >> x >> y >> z;
  if (x < 0) { x = -x; y = -y; z = -z; }

  int ans = x;
  if (0 < y && y < x) ans = z < y ? abs(z) + x - z : -1;
  cout << ans << endl;
  return 0;
}