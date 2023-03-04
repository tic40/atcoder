#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;

int main() {
  int n; cin >> n;
  vector<int> a(n);
  REP(i,n) cin >> a[i];

  vector dp(n+1,vector<ll>(2));
  REP(i,n) {
    dp[i+1][0] = max(dp[i+1][0], dp[i][0]);
    dp[i+1][1] = max(dp[i+1][1], dp[i][0]);
    dp[i+1][0] = max(dp[i+1][0], dp[i][1] + a[i]);
  }

  cout << max(dp[n][0], dp[n][1]) << endl;
  return 0;
}