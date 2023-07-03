#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;
using mint = modint1000000007;
using mintb = modint;

int main() {
  ll n; int b,k;
  cin >> n >> b >> k;
  vector<int> c(k);
  REP(i,k) cin >> c[i];

  mintb::set_mod(b);
  vector<mintb> power10(64);
  vector dp(64,vector<mint>(1009));
  vector ans(64,vector<mint>(1009));

  // 前計算
  REP(i,63) power10[i] = (mintb(10)).pow(1LL << i);
  // dp[0][i] を求める
  REP(i,k) dp[0][c[i] % b]++;

  REP(i,62) REP(j,b) REP(k,b) {
    int nex = (ll)(j * power10[i].val() + k) % b;
    dp[i+1][nex] += dp[i][j] * dp[i][k];
  }

  ans[0][0] = 1;
  REP(i,62) {
    if ((n & (1LL << i)) != 0LL) {
      REP(j,b) REP(k,b) {
        int nex = (ll)(j * power10[i].val() + k) % b;
        ans[i+1][nex] += ans[i][j] * dp[i][k];
      }
    } else {
      REP(j,b) ans[i+1][j] = ans[i][j];
    }
  }

  cout << ans[62][0].val() << endl;
  return 0;
}