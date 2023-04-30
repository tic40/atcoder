#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int h,w; cin >> h >> w;
  vector<string> a(h),b(h);
  REP(i,h) cin >> a[i];
  REP(i,h) cin >> b[i];

  // s: 縦方向shift数, t: 横方向shit数
  auto f = [&](int s, int t) {
    REP(i,h) REP(j,w) {
      int ni = (i+s) % h;
      int nj = (j+t) % w;
      if (a[ni][nj] != b[i][j]) return false;
    }
    return true;
  };

  int ok = 0;
  REP(i,h) REP(j,w) ok |= f(i,j);
  cout << (ok ? "Yes" : "No") << endl;
  return 0;
}