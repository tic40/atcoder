#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using mint = modint998244353; // modint1000000007;

int main() {
  int n; cin >> n;
  vector<int> a(n);
  REP(i,n) cin >> a[i];

  const int m = 10;
  const int m2 = 1<<(m+1);
  // dp[i][bit] := i 個まで決めて、作れる和の集合が bit である場合の数
  vector dp(n+1,vector<mint>(m2));
  dp[0][1] = 1; // 0 だけが作れる状態

  REP(i,n) REP(bit,m2) {
    dp[i][bit] /= a[i];
    for(int x = 1; x <= min(m,a[i]); x++) {
      dp[i+1][(bit | bit<<x)&(m2-1)] += dp[i][bit];
    }
    dp[i+1][bit] += dp[i][bit] * max(0,a[i]-m);
  }

  mint ans = 0;
  REP(bit,m2) if (bit>>m&1) ans += dp[n][bit];
  cout << ans.val() << endl;
  return 0;
}