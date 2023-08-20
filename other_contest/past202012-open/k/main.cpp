#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using P = pair<int,int>;
const int INF = numeric_limits<int>::max();

const vector<P> moves = {
  {0, 1}, {0, -1}, {1, 0}, {-1, 0}, {0, 0}
};

int main() {
  vector<string> s(4);
  REP(i,4) cin >> s[i];

  vector<double> dp(1<<16,INF);
  dp[0] = 0;
  for(int bit = 1; bit < 1<<16; bit++) {
    REP(i,4) REP(j,4) {
      int cnt = 0;
      double tot = 5;
      for(auto [dx,dy]: moves) {
        int ni = i+dx;
        int nj = j+dy;
        if (ni < 0 || nj < 0 || ni >= 4 || nj >= 4) continue;
        int now = 1 << (ni*4+nj);
        if ((bit & now) == 0) continue;
        cnt++;
        tot += dp[bit ^ now];
      }
      if (0 < cnt) dp[bit] = min(dp[bit], tot / cnt);
    }
  }

  int msk = 0;
  REP(i,4) REP(j,4) if (s[i][j] == '#') msk |= 1 << (i*4+j);
  printf("%.10f\n",dp[msk]);
  return 0;
}