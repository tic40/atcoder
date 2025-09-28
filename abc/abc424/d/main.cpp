#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {

  auto solve = []() {
    int h,w; cin >> h >> w;
    vector<string> s(h);
    REP(i,h) cin >> s[i];

    int ans = 9;
    auto f = [&](auto& f, int now) -> void {
      if (now >= ans) return;
      REP(i,h-1) REP(j,w-1) {
        int cnt = 0;
        REP(di,2) REP(dj,2) if (s[i+di][j+dj] == '#') cnt++;
        if (cnt != 4) continue;

        REP(di,2) REP(dj,2) {
          int ni = i+di, nj = j+dj;
          s[ni][nj] = '.';
          f(f,now+1);
          s[ni][nj] = '#';
        }
        return;
      }
      ans = min(ans,now);
    };
    f(f,0);

    return ans;
  };

  int t; cin >> t;
  REP(_,t) cout << solve() << endl;
  return 0;
}