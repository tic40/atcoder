#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
typedef long long ll;

int main() {
  int N, W; cin >> N >> W;
  int w[N],v[N]; REP(i,N) cin >> w[i] >> v[i];

  ll dp[N+1][W+1];
  REP(i,N+1) REP(j,W+1) dp[i][j] = 0;

  REP(i,N) REP(j,W+1) {
    dp[i+1][j] = dp[i][j];
    if (j-w[i] >= 0) {
      dp[i+1][j] = max(dp[i+1][j], dp[i][j-w[i]] + v[i]);
    }
  }
  cout << dp[N][W] << endl;
}