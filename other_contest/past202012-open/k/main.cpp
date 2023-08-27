#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;
using P = pair<int,int>;
const int INF = numeric_limits<int>::max();
const ll LINF = numeric_limits<ll>::max();
const int MOD = 1e9+7;
// using mint = modint998244353; // modint1000000007;

const vector<P> moves = {
  {0,0},
  {1,0},
  {-1,0},
  {0,1},
  {0,-1}
};

int main() {
  vector<string> s(4);
  REP(i,4) cin >> s[i];

  vector<double> dp(1<<16,INF);
  dp[0] = 0;
  REP(bit,1<<16) {
    REP(i,4) REP(j,4) {
      int cnt = 0;
      double tot = 5;
      for(auto [dx,dy]: moves) {
        int nx = i+dx;
        int ny = j+dy;
        if (nx < 0 || ny < 0 || nx >= 4 || ny >= 4) continue;
        int mask = 1 << (nx*4+ny);
        if ((bit & mask) == 0) continue;
        tot += dp[bit ^ mask];
        cnt++;
      }
      if (cnt) dp[bit] = min(dp[bit], tot / cnt);
    }
  }

  int x = 0;
  REP(i,4) REP(j,4) {
    if (s[i][j] == '#') x |= 1 << (i*4+j);
  }
  printf("%.10f\n",dp[x]);
  return 0;
}