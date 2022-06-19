#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
using ll = long long;

int n,d;
vector<ll> a;

// 包除原理解
ll solve1() {
  ll ans = 1LL << d;
  for(int i = 1; i < (1<<n); i++) {
    ll bit = 0;

    // フラグが立っているa[j]の論理和を取る
    REP(j,n) {
      if ((i >> j) & 1) bit |= a[j];
    }

    // d桁の中で0の数をカウントする
    int free_digits = d - __builtin_popcountll(bit);
    ll x = 1LL << free_digits;

    // 偶数なら足す、奇数なら引く
    ans += __builtin_popcountll(i) % 2 ? -x : x;
  }
  return ans;
}

// DP解
ll solve2() {
  // dp[i][j] := i桁目のjまでのaの組み合わせをみたときのパターン数
  vector<vector<ll>> dp(d+1,vector<ll>(1<<n));

  dp[0][0]=1;
  REP(i,d) {
    // a[j]の iビット目が1
    int m = 0;
    REP(j,n) {
      if (a[j] & (1LL << i)) m |= (1 << j);
    }
    REP(bit, 1<<n) {
      // iビット目を0にするとき
      dp[i+1][bit] += dp[i][bit];
      // iビット目を1にするとき
      dp[i+1][bit | m] += dp[i][bit];
    }
  }

  return dp[d][(1 << n) - 1];
}

int main() {
  cin >> n >> d;
  a.resize(n);
  REP(i,n) cin >> a[i];

  // cout << solve1() << endl;
  cout << solve2() << endl;
  return 0;
}