#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using mint = modint998244353;

int main() {
  int n,x; cin >> n >> x;
  vector<int> t(n);
  REP(i,n) cin >> t[i];

  // dp[i][j] := 時刻 i のときに j:0(1番目), j:1(1番目以外) の曲が流れているときの確率
  vector dp(x+2,vector<mint>(2));
  mint r = (mint)1/n;
  REP(i,n) dp[min(x+1,t[i])][i == 0 ? 0 : 1] += r;

  REP(i,x+1) REP(j,n) REP(k,2) {
    if (dp[i][k] == 0) continue;
    dp[min(x+1,i + t[j])][j == 0 ? 0 : 1] += dp[i][k]*r;
  }

  cout << dp[x+1][0].val() << endl;
  return 0;
}