#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
const int INF = 1e9;

// Sのi文字目までをTのj文字目までに一致させるための最小操作回数
int dp[1005][1005];

int main() {
  string s,t;
  cin >> s >> t;

  REP(i,1005) REP(j,1005) dp[i][j] = INF;
  dp[0][0] = 0;

  for (int i = -1; i < (int)s.size(); i++) {
    for (int j = -1; j < (int)t.size(); j++) {
      // 変更
      if (0 <= i && 0 <= j) {
        if (s[i] == t[j]) {
          dp[i+1][j+1] = min(dp[i+1][j+1], dp[i][j]);
        } else {
          dp[i+1][j+1] = min(dp[i+1][j+1], dp[i][j]+1);
        }
      }

      // 削除
      if (0 <= i) dp[i+1][j+1] = min(dp[i+1][j+1], dp[i][j+1]+1);

      // 挿入
      if (0 <= j) dp[i+1][j+1] = min(dp[i+1][j+1], dp[i+1][j]+1);
    }
  }

  cout << dp[s.size()][t.size()] << endl;
  return 0;
}