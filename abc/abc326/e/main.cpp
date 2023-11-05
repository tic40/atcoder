#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using mint = modint998244353;

int main() {
  int n; cin >> n;
  vector<int> a(n+1);
  REP(i,n) cin >> a[i+1];

  // dp[i] := x=iの状態からはじめたときの期待値
  vector<mint> dp(n+1);

  // WA. O(N^2)
  auto solve1 = [&]() {
    // 後ろから順に dp[i] を求めていく
    for(int i = n; i >= 0; i--) {
      mint s;
      for(int j = i+1; j <= n; j++) s+=dp[j];
      s /= n; // 期待値のため n で割る
      dp[i] = s+a[i]; // i に着地するには a[i] 円得ているため +a[i]
    }
    cout << dp[0].val() << endl;
  };

  auto solve2 = [&]() {
    mint s, p = mint(1)/n;
    for(int i = n; i >= 0; i--) {
      dp[i] = s * p + a[i];
      s += dp[i];
    }
    cout << dp[0].val() << endl;
  };

  // solve1();
  solve2();
  return 0;
}