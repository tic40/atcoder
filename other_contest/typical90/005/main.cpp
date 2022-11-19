#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'
using ll = long long;
using P = pair<int,int>;
const int INF = numeric_limits<int>::max();
const ll LINF = numeric_limits<ll>::max();
const int MOD = 1e9+7;
using mint = modint1000000007;

int main() {
  ll n;
  int b,k;
  cin >> n >> b >> k;
  vector<int> c(k);
  REP(i,k) cin >> c[i];

  // 小課題1
  vector dp(n+1,vector<mint>(b));
  dp[0][0] = 1;
  REP(i,n) {
    REP(j,b) {
      if (dp[i][j] == 0) continue;
      REP(l,k) {
        dp[i+1][ (j*10+c[l])%b ] += dp[i][j];
      }
    }
  }

  cout << dp[n][0].val() << endl;
  return 0;
}