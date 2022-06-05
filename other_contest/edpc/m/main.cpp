#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
using mint = modint1000000007;

int main() {
  int n,k; cin >> n >> k;
  vector<int> a(n);
  REP(i,n) cin >> a[i];

  // dp[i] = i個飴を分ける方法が何通りあるか
  vector<mint> dp(k+1);
  dp[0] = 1;
  REP(i,n) {
    vector<mint> p(k+1);
    swap(dp,p);
    vector<mint> m(k+2); // 累積和
    REP(j,k+1) m[j+1] = m[j] + p[j];
    REP(j,k+1) dp[j] = m[j+1] - m[max(0,j-a[i])];
  }

  cout << dp[k].val() << endl;
  return 0;
}