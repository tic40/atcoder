#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using mint = modint998244353;

int main() {
  int n,m; cin >> n >> m;

  // dp[i][j] := i 番目までみたとき、
  // j=0 のときは1番目に選んだ数とは異なる数
  // j=1 のときは1番目に選んだ数と同じ数
  // を選んだときの個数
  vector dp(n,vector<mint>(2));
  dp[0][1] = m;
  REP(i,n-1) {
    // 一つ前と異なる かつ 1番目と異なる数の選び方は m-2 通り
    dp[i+1][0] += dp[i][0] * (m-2);
    // 1番目と同じ数の選び方は 1 通り
    dp[i+1][1] += dp[i][0];
    // 1番目と同じ数を選んだ状態から 1番目と異なる数を選ぶのは m-1 通り
    dp[i+1][0] += dp[i][1] * (m-1);
  }
  cout << dp[n-1][0].val() << endl;
  return 0;
}