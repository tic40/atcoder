#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
using ll = long long;
const int INF = 1e9;
const int MOD = 1e9+7;

int main() {
  int n; cin >> n;
  vector<int> dp(n+1);
  dp[0] = 1;
  REP(i,n+1) {
    if (i > 0) dp[i] += dp[i-1];
    if (i > 1) dp[i] += dp[i-2];
    if (i > 2) dp[i] += dp[i-3];
  }

  cout << dp[n] << endl;
  return 0;
}