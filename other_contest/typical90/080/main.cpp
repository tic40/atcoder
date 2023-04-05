#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
using ll = long long;

// 包除原理解
ll solve1(int n, int d, vector<ll> a) {
  ll ans = 1LL << d;
  for(int i = 1; i < (1<<n); i++) {
    ll bit = 0;

    // フラグが立っている a[j] の論理和を取る
    REP(j,n) if (i >> j & 1) bit |= a[j];

    // d 桁の中で 0 の数をカウントする
    int free_digits = d - __builtin_popcountll(bit);
    ll x = 1LL << free_digits;

    // 偶数なら足す、奇数なら引く
    ans += __builtin_popcountll(i) % 2 ? -x : x;
  }
  return ans;
}

// DP解
ll solve2(int n, int d, vector<ll> a) {
  // dp[i][j] := i ビット目までみたときのパターン数
  vector<ll> dp(1<<n);
  dp[0] = 1;

  // i ビット目ごとに見ていく
  REP(i,d) {
    vector<ll> p(1<<n);
    swap(dp,p);
    // a[j] の i ビット目が立っているかの情報
    int m = 0;
    REP(j,n) if (a[j] >> i & 1) m |= (1<<j);

    REP(bit, 1<<n) {
      // i ビット目を 0 にするとき
      // (A[i] & x) != 0 となる m の集合は変わらないので、bit の内容はそのまま
      dp[bit] += p[bit];
      // i ビット目を 1 にするとき
      // A[i] の i bit目が 1 であるような m が集合に加わるので bit の値もそれに従って改める
      dp[bit | m] += p[bit];
    }
  }

  return dp.back();
}

int main() {
  int n,d; cin >> n >> d;
  vector<ll> a(n);
  REP(i,n) cin >> a[i];

  // cout << solve1(n,d,a) << endl;
  cout << solve2(n,d,a) << endl;
  return 0;
}