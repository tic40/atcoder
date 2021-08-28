#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
using ll = long long;
const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;

int main() {
  int n,x,y;
  cin >> n >> x >> y;

  vector<int> dp(n+1);
  dp[0] = x;
  dp[1] = y;

  for(int i = 2; i < n; i++) {
    dp[i] = dp[i-1] + dp[i-2];
    dp[i] %= 100;
  }

  cout << dp[n-1] << endl;
  return 0;
}