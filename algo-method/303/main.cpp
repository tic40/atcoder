#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
const int INF = 1e9;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);

  REP(i,n) cin >> a[i];
  vector<int> dp(n+1, INF);
  dp[0] = 0;

  REP(i,n) {
    if (i > 0) dp[i] = min(dp[i], dp[i-1] + a[i]);
    if (i > 1) dp[i] = min(dp[i], dp[i-2] + 2*a[i]);
  }
  cout << dp[n-1] << endl;
  return 0;
}