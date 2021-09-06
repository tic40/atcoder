#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)

int main() {
  int n;
  cin >> n;
  vector<int> w(n);
  REP(i,n) cin >> w[i];

  vector<bool> dp(1005);
  dp[0] = true;

  REP(i,n) {
    vector<bool> dp2(1005);
    swap(dp2,dp);
    REP(j,1001) {
      if (dp2[j]) {
        if (j+w[i] <= 1000) dp[j+w[i]] = true;
        dp[abs(j-w[i])] = true;
      }
    }
  }

  REP(j,1001) {
    if (!dp[j]) continue;
    cout << j << endl;
    break;
  }

  return 0;
}