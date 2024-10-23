#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using mint = modint1000000007;

int main() {
  int h,w,k; cin >> h >> w >> k; k--;

  vector dp(h+1,vector<mint>(w+1));
  dp[0][0]=1;

  // bits := 連続しない横線パターンの集合
  vector<int> bits;
  REP(bit,1<<(w-1)) {
    bool ok = true;
    REP(i,w-2) if ((bit >> i & 1) && (bit >> (i+1) & 1)) ok = false;
    if (ok) bits.push_back(bit);
  }

  REP(i,h) REP(j,w) for(auto bit: bits) {
    // 左方向へ移動
    if (j > 0 && (bit >> (j-1) & 1)) dp[i+1][j-1] += dp[i][j];
    // 右方向へ移動
    else if (j < w-1 && (bit >> j & 1)) dp[i+1][j+1] += dp[i][j];
    // 真下へ移動
    else dp[i+1][j] += dp[i][j];
  }

  cout << dp[h][k].val() << endl;
  return 0;
}