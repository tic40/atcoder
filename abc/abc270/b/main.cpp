#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'

int main() {
  int x,y,z; cin >> x >> y >> z;
  if (x < 0) { x = -x; y = -y; z = -z; }

  int ans = -1;
  if (0 < y && y < x) {
    if (z < y) ans = abs(z) + (x - z);
  } else {
    ans = x;
  }

  cout << ans << endl;
  return 0;
}