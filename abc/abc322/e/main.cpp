#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;
const ll LINF = numeric_limits<ll>::max();

int main() {
  int n,k,p; cin >> n >> k >> p;
  vector<int> c(n);
  vector a(n,vector<int>(k));
  REP(i,n) {
    cin >> c[i];
    REP(j,k) cin >> a[i][j];
  }

  int sn = pow(10,k);
  // dp[i][j] := i 個までみたとき、パラメータ集合が j のときの最小コスト
  vector dp(n+1,vector<ll>(sn, LINF));
  dp[0][0] = 0;
  REP(i,n) REP(s,sn) {
    if (dp[i][s] == LINF) continue;

    // 選ばない
    dp[i+1][s] = min(dp[i+1][s],dp[i][s]);

    // 選ぶ
    int x = 1, nex = s;
    REP(j,k) {
      int now = nex / x % 10; // 現在のパラメータ値
      nex += (min(p, now + a[i][j]) - now) * x;
      x *= 10;
    }
    dp[i+1][nex] = min(dp[i+1][nex],dp[i][s] + c[i]);
  }

  int x = 1, t = 0;
  REP(i,k) { t += p * x; x *= 10; }
  if (dp[n][t] == LINF) dp[n][t] = -1;
  cout << dp[n][t] << endl;
  return 0;
}