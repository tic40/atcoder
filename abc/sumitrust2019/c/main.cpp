#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)

int main() {
  int x; cin >> x;
  vector<bool> dp(x+1);
  dp[0] = true;

  REP(i,x+1) REP(j,6) {
    int from = i - (100+j);
    dp[i] = dp[i] || (from >= 0 && dp[from]);
  }

  cout << dp[x] << endl;
  return 0;
}