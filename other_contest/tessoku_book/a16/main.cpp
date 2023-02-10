#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n; cin >> n;
  vector<int> a(n-1),b(n-2);
  REP(i,n-1) cin >> a[i];
  REP(i,n-2) cin >> b[i];

  vector<int> dp(n+5,1e9);
  dp[0] = 0;
  REP(i,n) {
    if(i-1 >= 0) dp[i] = min(dp[i], dp[i-1] + a[i-1]);
    if(i-2 >= 0) dp[i] = min(dp[i], dp[i-2] + b[i-2]);
  }
  cout << dp[n-1] << endl;
  return 0;
}