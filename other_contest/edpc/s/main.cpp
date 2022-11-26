#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'
using mint = modint1000000007;

int main() {
  string k; int d;
  cin >> k >> d;
  int n = k.size();

  // dp[i][j][l] := 上からi桁目まで確定していて
  // 各桁の総和%dがlで、K未満かどうか確定or未確定(j=1なら確定)で条件を満たすもの
  vector dp(n+1,vector(2,vector<mint>(d)));
  dp[0][0][0]=1;
  REP(i,n) REP(j,d) {
    int nk = k[i]-'0';
    // K未満からのK未満への遷移
    // この場合、0〜9どれでもok
    REP(dig,10) dp[i+1][1][(j+dig)%d] += dp[i][1][j];
    // Kより大きい、からK未満への遷移
    REP(dig,nk) dp[i+1][1][(j+dig)%d] += dp[i][0][j];
    // Kより大きいからKより大きいへの遷移
    dp[i+1][0][(j+nk)%d] += dp[i][0][j];
  }
  cout << (dp[n][0][0] + dp[n][1][0] - 1).val() << endl;
  return 0;
}