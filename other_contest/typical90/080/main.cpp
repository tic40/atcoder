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
    REP(j,n) if (i >> j & 1) bit |= a[j];

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
  vector<ll> dp(1<<n);
  dp[0]=1;

  REP(i,d) {
    vector<ll> p(1<<n);
    swap(dp,p);

    int m = 0;
    REP(j,n) if (a[j] >> i & 1) m |= (1<<j);

    REP(bit, 1<<n) {
      if (p[bit] == 0) continue;
      // iビット目を0にするとき
      // (Ai&x) ≠ 0 となる m の集合は変わらないので、bitsの内容はそのまま
      dp[bit] += p[bit];
      // iビット目を1にするとき
      // Ai の iビット目が 1 であるような m が集合に加わるので、bitsの値もそれに従って改める
      dp[bit|m] += p[bit];
    }
  }

  return dp.back();
}

int main() {
  cin >> n >> d;
  a.resize(n);
  REP(i,n) cin >> a[i];

  // cout << solve1() << endl;
  cout << solve2() << endl;
  return 0;
}