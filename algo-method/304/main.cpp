#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
const int INF = 1e9;

int main() {
  int n; cin >> n;
  vector<int> dp(n+2,0);
  dp[0] = 1;
  REP(i,n) {
    dp[i+1] += dp[i];
    dp[i+2] += dp[i];
  }

  cout << dp[n] << endl;
  return 0;
}