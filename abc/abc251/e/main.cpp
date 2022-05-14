#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
using ll = long long;
const ll LINF = 1e18+5;

ll dp[300005][2][2]; // [i][j][k] := i番目, j支払ったかどうか, k 最初か最後どちらを決め打ちで支払ったか

int main() {
  int n; cin >> n;
  vector<int> a(n);
  REP(i,n) cin >> a[i];

  REP(i,n) {
    if (i == 0) dp[i+1][0][0] = LINF;
    else dp[i+1][0][0] = dp[i][1][0];
    dp[i+1][1][0] = min(dp[i][0][0],dp[i][1][0]) + a[i];

    dp[i+1][0][1] = dp[i][1][1];
    dp[i+1][1][1] = min(dp[i][0][1],dp[i][1][1]) + a[i];
  }

  cout << min(dp[n][1][1], min(dp[n][0][0],dp[n][1][0])) << endl;
  return 0;
}
