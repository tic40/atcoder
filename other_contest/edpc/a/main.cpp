#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)

int main() {
  int n; cin >> n;
  vector<int> h(n+2);
  REP(i,n) cin >> h[i];

  vector<int> dp(n+2, 1e9);
  dp[0] = 0;
  REP(i,n) {
    dp[i+1] = min(dp[i+1], dp[i] + abs(h[i]-h[i+1]));
    dp[i+2] = min(dp[i+2], dp[i] + abs(h[i]-h[i+2]));
  }

  cout << dp[n-1] << endl;
  return 0;
}