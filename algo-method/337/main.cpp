#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)

int main() {
  int n,m;
  cin >> n >> m;
  vector<int> w(n);
  REP(i,n) cin >> w[i];

  vector<bool> dp(m+1, false);
  dp[0]=true;

  REP(i,n) REP(j,m+1) {
    if (w[i]<=j) dp[j] = dp[j] || dp[j-w[i]];
  }

  cout << (dp[m] ? "Yes" : "No") << endl;
  return 0;
}