#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int h,w,d; cin >> h >> w >> d;
  vector<string> s(h);
  REP(i,h) cin >> s[i];

  int ans = 0;
  REP(i1,h) REP(j1,w) REP(i2,h) REP(j2,w) if (s[i1][j1] == '.' && s[i2][j2] == '.') {
    auto t = s;
    auto f = [&](int ni, int nj) {
      int res = 0;
      for(int i = max(0,ni-d); i <= min(h-1,i+d); i++) {
        for(int j = max(0,nj-d); j <= min(w-1,j+d); j++) {
          int nd = abs(i-ni) + abs(j-nj);
          if (nd <= d && t[i][j] == '.') { res++; t[i][j] = '#'; }
        }
      }
      return res;
    };
    ans = max(ans, f(i1,j1)+f(i2,j2));
  }
  cout << ans << endl;
  return 0;
}