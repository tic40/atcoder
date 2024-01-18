#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using mint = modint998244353;

int main() {
  int n; cin >> n;
  vector<int> a(n);
  REP(i,n) cin >> a[i];

  // 平方分割
  const int D = sqrt(n);
  vector s(D, vector<mint>(n));
  vector<mint> dp(n+1); // dp[i] := i からスタートしたときの集合の数
  dp[0] = 1;

  REP(i,n) {
    REP(j,D) {
      dp[i] += s[j][i];
      if (i+j < n) s[j][i+j] += s[j][i];
    }
    // 平方分割
    if (a[i] < D) {
      if (i+a[i] < n) s[a[i]][i+a[i]] += dp[i];
    } else {
      for(int j = i+a[i]; j < n; j += a[i]) dp[j] += dp[i];
    }
  }

  mint ans = 0;
  REP(i,n) ans += dp[i];
  cout << ans.val() << endl;
  return 0;
}