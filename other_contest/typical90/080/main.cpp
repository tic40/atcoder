#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
using ll = long long;

int main() {
  int n,d; cin >> n >> d;
  vector<ll> a(n);
  REP(i,n) cin >> a[i];

  auto solve1 = [&]() { // 包除原理解法
    ll ans = 1LL << d;
    for(int bit = 1; bit < (1<<n); bit++) {
      ll s = 0;
      // bit の立っている a[i] の論理和
      REP(i,n) if (bit >> i & 1) s |= a[i];
      // d 桁の中で 0 の数をカウントする
      int free_digits = d - __builtin_popcountll(s);
      ll add = 1LL << free_digits;

      // bit の立っている数が偶数なら足す、奇数なら引く
      ans += __builtin_popcount(bit) % 2 ? -add : add;
    }
    return ans;
  };

  auto solve2 = [&]() { // DP解
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

    return dp[(1<<n)-1];
  };

  cout << solve1() << endl;
  // cout << solve2() << endl;
  return 0;
}