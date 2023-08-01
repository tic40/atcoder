#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using mint = modint998244353;

int main() {
  int n,m; cin >> n >> m;
  vector<string> s(n);
  REP(i,n) cin >> s[i];

  // 初期状態を美しい状態になるように更新する
  REP(i,n) REP(j,m) {
    if (s[i][j] == '.') continue;
    if (i+1 < n) s[i+1][j] = '#';
    if (i+1 < n && j+1 < m) s[i+1][j+1] = '#';
  }

  // 解説放送解 https://www.youtube.com/watch?v=OA4q9-u8ecg
  auto solve1 = [&]() {
    // dp[n+1][0] := 左上の白マス領域の経路の総数
    vector dp(n+2,vector<mint>(m+1));
    dp[0][m]=1;
    for(int j = m; j >= 0; j--) REP(i,n+2) {
      if (i+1 < n+2) dp[i+1][j] += dp[i][j];
      if (i-1 >= 0 && j-1 >= 0) {
        if (i == 1 || s[i-2][j-1] == '.') dp[i-1][j-1] += dp[i][j];
      }
    }
    cout << dp[n+1][0].val() << endl;
  };

  // 解説解 https://atcoder.jp/contests/abc311/editorial/6822
  auto solve2 = [&]() {
    vector<mint> dp(m+1);
    dp[m]=1;
    for(int c = -m+1; c <= n-1; c++) {
      for(int j = m-1; j >= 0; j--) dp[j]+=dp[j+1];
      REP(j,m) {
        int i = j+c;
        if (i < 0) dp[j] = 0;
        else if (i >= n || s[i][j] == '#') dp[j+1] = 0;
      }
    }
    mint ans = 0;
    for(auto v: dp) ans += v;
    cout << ans.val() << endl;
  };

  solve1();
  // solve2();
  return 0;
}