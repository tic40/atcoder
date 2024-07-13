#include <bits/stdc++.h>
using namespace std;

int main() {
  int r,g,b; cin >> r >> g >> b;
  string c; cin >> c;
  int ans = 1e9;
  if (c != "Red") ans = min(ans,r);
  if (c != "Green") ans = min(ans,g);
  if (c != "Blue") ans = min(ans,b);
  cout << ans << endl;
  return 0;
}