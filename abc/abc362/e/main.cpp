#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;
using mint = modint998244353;

int main() {
  int n; cin >> n;
  vector<int> a(n);
  REP(i,n) cin >> a[i];

  // dp[i][k] := i 個目まで見たとき、a[i] を含む長さ k の部分列で等差が d の場合の数
  vector dp(n,vector<map<int,mint>>(n+1));
  REP(i,n) REP(j,i) {
    int d = a[i] - a[j];
    for(int k = 1; k <= n; k++) if (dp[j][k].count(d)) {
      dp[i][k+1][d] += dp[j][k][d];
    }
    dp[i][2][d]++;
  }

  vector<mint> ans(n+1);
  ans[1] = n;
  REP(i,n) for (int k = 1; k <= n; k++) {
    for (auto [_,v]: dp[i][k]) ans[k] += v;
  }

  for (int k = 1; k <= n; k++) cout << ans[k].val() << " ";
  return 0;
}