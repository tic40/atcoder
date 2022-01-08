#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
typedef long long ll;
const int INF = 1001001001;

int main() {
  int n,k;
  cin >> n >> k;
  int h[n];
  REP(i, n) cin >> h[i];

  int dp[n];
  REP(i,n+1) dp[i] = INF;

  dp[0] = 0;
  for (int i = 1; i < n; i++) {
    for (int j = 1; j <= k; j++) {
      if (i-j < 0) break;
      int cost = dp[i-j] + abs(h[i-j]-h[i]);
      dp[i] = min(dp[i],cost);
    }
  }
  cout << dp[n-1] << endl;
}