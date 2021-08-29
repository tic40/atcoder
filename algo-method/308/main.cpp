#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)

int dp[105][1005]; // dp[i][j] := i番目までの品物を選んだときの重さがj以下のときの価値の最大値

int main() {
  int N,W;
  cin >> N >> W;
  vector<int> w(N),v(N);
  REP(i,N) cin >> w[i] >> v[i];

  REP(i,N) {
    REP(j,W+1) {
      if (j - w[i] >= 0) {
        dp[i+1][j] = max(dp[i][j], dp[i][j-w[i]] + v[i]);
      } else {
        dp[i+1][j] = dp[i][j];
      }
    }
  }

  cout << dp[N][W] << endl;
  return 0;
}