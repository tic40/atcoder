#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int h,w,d; cin >> h >> w >> d;
  vector<string> s(h);
  REP(i,h) cin >> s[i];

  vector g(h,vector<int>(w));

  auto f = [&](int x, int y) -> void {
    for(int i = x-d; i <= x+d; i++) {
      for(int j = y-d; j <= y+d; j++) {
        if (i < 0 || j < 0 || i >= w || j >= h) continue;
        int dist = abs(x-i) + abs(y-j);
        if (dist > d) continue;
        if (s[j][i] == '#') continue;
        g[j][i] = 1;
      }
    }
  };

  int ans = 0;
  REP(i,h*w) REP(j,h*w) if (i != j) {
    int x1 = i % w;
    int y1 = i / w;
    int x2 = j % w;
    int y2 = j / w;

    if (s[y1][x1] == '#' || s[y2][x2] == '#') continue;
    g = vector(h,vector<int>(w));
    f(x1,y1);
    f(x2,y2);
    int now = 0;
    REP(i,h) REP(j,w) now += g[i][j];
    ans = max(ans,now);
  }
  cout << ans << endl;
  return 0;
}