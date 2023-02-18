#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n; cin >> n;
  vector<int> a(n);
  REP(i,n) cin >> a[i];

  vector dp(n,vector<int>(n));
  REP(i,n) dp[n-1][i] = a[i];

  for(int i = n-2; i >= 0; i--) REP(j,i+1) {
    int d1 = dp[i+1][j];
    int d2 = dp[i+1][j+1];
    dp[i][j] = i % 2 == 0 ? max(d1,d2) : min(d1,d2);
  }

  cout << dp[0][0] << endl;
  return 0;
}