#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)

int main() {
  int h,w,r,c;
  cin >> h >> w >> r >> c;

  int ans = 0;
  if (1 <= r-1) ans++;
  if (r+1 <= h) ans++;
  if (1 <= c-1) ans++;
  if (c+1 <= w) ans++;
  cout << ans << endl;

  return 0;
}