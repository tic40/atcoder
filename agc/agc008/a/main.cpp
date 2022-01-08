#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)

int main() {
  int x,y;
  cin >> x >> y;

  int ans = 1e9+5;
  if (x <= y) ans = min(ans, y-x);
  if (-x <= y) ans = min(ans, y+x+1);
  if (x <= -y) ans = min(ans, -y-x+1);
  if (-x <= -y) ans = min(ans, -y+x+2);

  cout << ans << endl;
  return 0;
}