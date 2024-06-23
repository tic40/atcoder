#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;
using P = pair<int,int>;
const int INF = numeric_limits<int>::max();
const ll LINF = numeric_limits<ll>::max();
const int MOD = 1e9+7;
using mint = modint998244353; // modint1000000007;

struct Combination {
  vector<mint> fact, ifact;
  Combination(int n):fact(n+1),ifact(n+1) {
    fact[0] = 1;
    for (int i = 1; i <= n; ++i) fact[i] = fact[i-1]*i;
    ifact[n] = fact[n].inv();
    for (int i = n; i >= 1; --i) ifact[i-1] = ifact[i]*i;
  }
  mint operator()(int n, int k) {
    if (k < 0 || k > n) return 0;
    return fact[n]*ifact[k]*ifact[n-k];
  }
};

int main() {
  const int n = 26;
  int k; cin >> k;
  vector<int> c(n);
  REP(i,n) cin >> c[i];

  Combination comb(1000);
  // dp[i][j] := 文字種　i まで置いて j 個置いたときの個数
  vector<mint> dp(k+1);
  dp[0] = 1;
  REP(i,n) {
    vector<mint> p(k+1);
    swap(dp,p);
    REP(j,k+1) REP(a,c[i]+1) {
      int nj = j+a;
      if (nj > k) break;
      dp[nj] += p[j] * comb(nj,a);
    }
  }

  mint ans;
  REP(i,k) ans += dp[i+1];
  cout << ans.val() << endl;
  return 0;
}