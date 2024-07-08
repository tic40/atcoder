#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using mint = modint1000000007;

int main() {
  int n; cin >> n;
  vector a(n,vector<int>(n));
  REP(i,n) REP(j,n) cin >> a[i][j];

  // dp[bit] := 女性の bit 集合が男性とペアになっているときの組み合わせ数
  vector<mint> dp(1<<n);
  dp[0] = 1;
  REP(bit,(1<<n)-1) REP(i,n) {
    // popcount 番目の男性が i 番目の女性とペアになる遷移
    if ((bit >> i & 1) == 0 && a[__builtin_popcount(bit)][i]) {
      int nbit = bit | (1 << i);
      dp[bit | (1<<i)] += dp[bit];
    }
  }

  cout << dp[(1<<n)-1].val() << endl;
  return 0;
}