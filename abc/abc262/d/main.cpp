#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'
using mint = modint998244353;

int main() {
  int n; cin >> n;
  vector<int> a(n);
  REP(i,n) cin >> a[i];

  mint ans = 0;
  for(int i = 1; i <= n; i++) {
    // dp[j][k][l] := A の先頭 j 項から k 個の項を選ぶ方法であって、
    // 選んだ項の総和を i で割った余りが l となるようなものの個数
    vector dp(n+1,vector(i+1,vector<mint>(i)));
    dp[0][0][0] = 1;
    REP(j,n) {
      for(int k = 0; k <= i; k++) {
        for(int l = 0; l < i; l++) {
					dp[j+1][k][l] += dp[j][k][l];
					if (k!=i) dp[j+1][k+1][(l+a[j])%i] += dp[j][k][l];
        }
      }
    }
    ans += dp[n][i][0];
  }

  cout << ans.val() << endl;
  return 0;
}