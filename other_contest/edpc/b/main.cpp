#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
const int INF = 1e9;

int main() {
  int n,k; cin >> n >> k;
  vector<int> h(n);
  REP(i,n) cin >> h[i];

  vector<int> dp(n, INF);
  dp[0] = 0;
  REP(i,n) for (int j = 1; j <= k; j++) {
    if (i-j < 0) break;
    dp[i] = min(dp[i], dp[i-j] + abs(h[i]-h[i-j]));
  }

  cout << dp[n-1] << endl;
  return 0;
}