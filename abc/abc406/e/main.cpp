#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;
using mint = modint998244353; // modint1000000007;

const int m = 60;
// 桁 DP
// dp[i][j][s][p] := 上から i 桁決めて
//   j: 0/1, すでに丸をつけたかどうか
//   s: 0/1, n 未満が確定したかどうか 未満フラグ
//   p: 1 の数(popcount)
// ときの総和
vector dp(m+1,vector(2,vector(2,vector<mint>(m+1))));

// 解説放送解
void solve1() {
  ll n; int k; cin >> n >> k;
  n++; // 未満フラグにするために +1 しておく

  // init
  REP(i,m+1) REP(j,2) REP(s,2) REP(p,k+1) dp[i][j][s][p] = 0;
  dp[m][0][0][0] = 1;

  for(int i = m-1; i >= 0; i--) {
    REP(j,2) REP(s,2) REP(p,k+1) {
      mint now = dp[i+1][j][s][p]; // 上の桁から見ているので、一つ前は i+1
      if (now == 0) continue; // 遷移元がないので skip
      REP(a,2) { // a := 今見ている桁の bit を立てるかどうか
        int ns = s, np = p+a;
        if (s == 0) { // ここまで n と一致しているとき
          if (a < (n>>i&1)) ns = 1; // 未満フラグ立てる
          if (a > (n>>i&1)) continue; // n より大きくなるので skip
        }
        if (np > k) continue; // popcount が k より大きくなるので skip
        dp[i][j][ns][np] += now;
        if (j == 0 && a == 1) dp[i][1][ns][np] += now*(1LL<<i);
      }
    }
  }
  cout << dp[0][1][1][k].val() << endl;
}

// dp1[i][j][k]
//  i: i 桁目まで見て
//  j: 未満フラグ
//  k: popcount
//  dp1,2 はそれぞれ dp1: 総和, dp2: 場合の数 を管理する
vector dp1(m+1,vector(2,vector<mint>(m+1)));
vector dp2(m+1,vector(2,vector<mint>(m+1)));

void solve2() {
  ll n; int k; cin >> n >> k;
  n++; // 未満フラグで答えを出せるように +1

  REP(i,m+1) REP(j,2) REP(p,k+1) dp1[i][j][p] = dp2[i][j][p] = 0;
  dp2[0][0][0] = 1;

  REP(i,m) {
    REP(j,2) REP(p,k+1) {
      // a: 上から i 桁目の bit を立てるかどうか
      REP(a,2) if (p+a <= k) {
        int nj = j; // 次の未満 flag
        int np = p+a; // 次の popcount 数
        if (!j) { // 未満 flag = false. ここまで n と一致しているとき
          if (a < (n>>(m-i-1)&1)) nj = 1;
          if (a > (n>>(m-i-1)&1)) continue; // n 以上になるので不可
        }
        // 桁が1つ増えるので総和を * 2
        dp1[i+1][nj][np] += dp1[i][j][p] * 2;
        // bit を立てるときは場合の数分を足す
        if (a > 0) dp1[i+1][nj][np] += dp2[i][j][p];
        // 場合の数を更新
        dp2[i+1][nj][np] += dp2[i][j][p];
      }
    }
  }
  cout << dp1[m][1][k].val() << endl;
}

int main() {
  int t; cin >>t;
  REP(_,t) solve2();
  return 0;
}