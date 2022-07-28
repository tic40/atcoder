#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'
using ll = long long;
const int MOD = 1e9+7;

int main() {
  int n; cin >> n;
  // dp[i][j] = i個の数列の中に
  // 00: 0も9も含まない
  // 01: 0を含む
  // 10: 9を含む
  // 11: 0と9を含む
  vector dp(n+1, vector<ll>(1<<2));
  dp[0][0] = 1;
  REP(i,n) {
    REP(j,1<<2) REP(k,(1<<2)-1) {
      ll add = k == 0 ? dp[i][j] * 8 : dp[i][j];
      dp[i+1][j|k] += add;
      dp[i+1][j|k] %= MOD;
    }
  }

  cout << dp[n][3] << endl;
  return 0;
}