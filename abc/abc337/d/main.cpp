#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
const int INF = numeric_limits<int>::max();

int main() {
  int h,w,k; cin >> h >> w >> k;
  vector<string> s(h);
  REP(i,h) cin >> s[i];

  // rs := s を 90 度回転したもの
  vector<string> rs(w,string(h,'.'));
  REP(i,w) REP(j,h) rs[i][j] = s[h-1-j][i];

  int ans = INF;
  auto f = [&](int h, int w, vector<string> s) -> void {
    // 累積和
    vector sx(h,vector<int>(w+1));
    vector sd(h,vector<int>(w+1));
    REP(i,h) REP(j,w) {
      sx[i][j+1] = sx[i][j] + (s[i][j] == 'x' ? 1 : 0);
      sd[i][j+1] = sd[i][j] + (s[i][j] == '.' ? 1 : 0);
    }

    REP(i,h) REP(j,w-k+1) {
      if (sx[i][j+k] - sx[i][j] > 0) continue;
      ans = min(ans, sd[i][j+k] - sd[i][j]);
    }
  };

  f(h,w,s);
  f(w,h,rs);
  cout << (ans == INF ? -1 : ans) << endl;
  return 0;
}