#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i=0;i<n;i++)
using ll = long long;
const int MOD = 1e9+7;

int n;
int dp[1000010][2][2]; // [N][0を含むかどうか][9を含むかどうか]

ll modpow(ll x, ll y) {
  ll v = 1;
  REP(i,y) { v *= x; v %= MOD; }
  return v;
}

// 包除原理解法
void solve1() {
  ll p1 = modpow(10, n);
  ll p2 = (modpow(9, n) * 2) % MOD;
  ll p3 = modpow(8, n);
  ll ans = p1 - (p2 - p3);
  ans %= MOD;
  ans = (ans + MOD) % MOD;
  cout << ans << endl;
}

// DP解法
void solve2() {
  dp[0][0][0] = 1;
  REP(i,n) {
    REP(j,2) {
      REP(k,2) {
        REP(x,10) {
          int nj = j | x == 0;
          int nk = k | x == 9;
          dp[i+1][nj][nk] += dp[i][j][k];
          dp[i+1][nj][nk] %= MOD;
        }
      }
    }
  }
  cout << dp[n][1][1] << endl;
}

int main() {
  cin >> n;
  // solve1();
  solve2();
  return 0;
}