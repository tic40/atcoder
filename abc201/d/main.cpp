#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
const int INF = 1e9;

int h,w;
vector<string> a;

int solve() {
  int s[h][w];
  REP(i,h) REP(j,w) s[i][j] = a[i][j] == '+' ? 1 : -1;

  // dp[i][j] := i,j地点でのtakahashiのスコア - aokiのスコアの最良スコア
  int dp[h][w];
  REP(i,h) REP(j,w) dp[i][j] = -INF; // dp初期値
  dp[h-1][w-1] = 0; // 右下は0

  // 右下から順番にみていく
  for(int i = h-1; 0 <= i; i--) {
    for(int j = w-1; 0 <= j; j--) {
      if (i < h-1) dp[i][j] = max(dp[i][j], s[i+1][j] - dp[i+1][j]); // 下
      if (j < w-1) dp[i][j] = max(dp[i][j], s[i][j+1] - dp[i][j+1]); // 右
    }
  }
  return dp[0][0];
}

int main() {
  cin >> h >> w;
  a.resize(h);
  REP(i,h) cin >> a[i];

  int score = solve();
  if (0 < score) cout << "Takahashi" << endl;
  else if (score < 0) cout << "Aoki" << endl;
  else cout << "Draw" << endl;

  return 0;
}