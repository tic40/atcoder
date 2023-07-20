#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using mint = modint1000000007;
using P = pair<int,int>;

const vector<P> moves = {
  {-1,-1}, {-1,0}, {-1,1},
  {0,-1}, {0,1},
  {1,-1}, {1,0}, {1,1}
};

int main() {
  int h,w; cin >> h >> w;
  vector<string> c(h);
  REP(i,h) cin >> c[i];

  vector<int> cnt(25);
  vector used(25,vector<bool>(25));
  vector nex0(25, vector<int>(1 << 18));
  vector nex1(25, vector<int>(1 << 18));
  vector state(25, vector<int>(1 << 18));
  vector< map<int,pair<int,bool>> > mp(25);
  vector dp(25, vector(25,vector<mint>(1 << 18)));

  auto judge = [&](int sx, int sy) {
    for(auto [dx,dy]: moves) {
      int tx = sx + dx;
      int ty = sy + dy;
      if (tx < 0 || ty < 0 || ty >= w) continue;
      if (used[tx][ty]) return false;
    }
    return true;
  };

  auto dfs = [&](auto self, int pos, int dep, int str) {
    int sx = pos/w, sy = pos % w;
    if (dep == w+1) {
      int idx = cnt[sy];
      state[sy][idx] = str;
      mp[sy][str] = {idx,judge(sx,sy)};
      cnt[sy]++;
      return;
    }
    self(self, pos+1, dep+1, str);
    if (!judge(sx,sy)) return;

    used[sx][sy] = true;
    self(self,pos+1,dep+1,str + (1 << dep));
    used[sx][sy] = false;
  };

  // initialize
  REP(i,w) dfs(dfs,i,0,0);

  // dp
  REP(i,w) REP(j,cnt[i]) {
    int t = state[i][j];
    int t0 = t >> 1;
    int t1 = (t >> 1) + (1 << w);
    nex0[i][j] = mp[(i+1) % w][t0].first;
    if (mp[i][t].second) nex1[i][j] = mp[(i+1) % w][t1].first;
    else nex1[i][j] = -1;
  }

  dp[0][0][0] = 1;
  REP(i,h) REP(j,w) {
    int n1 = i, n2 = j+1;
    if (n2 == w) { n1++; n2 = 0; }

    REP(k,cnt[j]) {
      if (dp[i][j][k] == 0) continue;
      dp[n1][n2][nex0[j][k]] += dp[i][j][k];
      if (nex1[j][k] != -1 && c[i][j] == '.') dp[n1][n2][nex1[j][k]] += dp[i][j][k];
    }
  }

  mint ans = 0;
  REP(i,cnt[0]) ans += dp[h][0][i];
  cout << ans.val() << endl;
  return 0;
}