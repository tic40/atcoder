#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'
using mint = modint1000000007;

int main() {
  int h,w;
  cin >> h >> w;
  vector<string> s(h);
  REP(i,h) cin >> s[i];

  vector dp(h+1, vector<mint> (w+1));
  // 3方向それぞれの累積和
  vector dpx(h+1, vector<mint> (w+1));
  vector dpy(h+1, vector<mint> (w+1));
  vector dpxy(h+1, vector<mint> (w+1));
  dp[0][0] = 1;
  dpx[0][0] = 1;
  dpy[0][0] = 1;
  dpxy[0][0] = 1;

  REP(i,h) REP(j,w) {
    if (i == 0 && j == 0) continue;
    if (s[i][j] == '#') continue;

    if (i > 0) dpx[i][j] += dpx[i-1][j];
    if (j > 0) dpy[i][j] += dpy[i][j-1];
    if (i > 0 && j > 0) dpxy[i][j] += dpxy[i-1][j-1];

    dp[i][j] += dpx[i][j] + dpy[i][j] + dpxy[i][j];

    dpx[i][j] += dp[i][j];
    dpy[i][j] += dp[i][j];
    dpxy[i][j] += dp[i][j];
  }

  cout << dp[h-1][w-1].val() << endl;
  return 0;
}