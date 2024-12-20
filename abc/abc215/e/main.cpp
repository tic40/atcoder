#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using mint = modint998244353;

int main() {
  int n; string s; cin >> n >> s;
  const int m = 10;

  vector dp(1<<m, vector<mint>(m));
  REP(i,n) {
    int a = s[i] - 'A';
    vector old(1<<m, vector<mint>(m));
    swap(dp,old);
    REP(bit, 1<<m) REP(j,m) if (bit >> j & 1) {
      dp[bit][j] += old[bit][j];
      // 最後に選んだコンテストと同じとき
      if (j == a) dp[bit][j] += old[bit][j];
      // 最後に選んだコンテストと異なり、かつまだ出場していないコンテスト種類のとき
      else if ((bit>>a&1) == 0) dp[bit|1<<a][a] += old[bit][j];
    }
    // a だけ選ぶとき
    dp[1<<a][a] += 1;
  }

  mint ans = 0;
  REP(bit, 1<<m) REP(j,10) ans += dp[bit][j];
  cout << ans.val() << endl;
  return 0;
}