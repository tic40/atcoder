#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using mint = modint998244353;

int main() {
  int n,m,k; cin >> n >> m >> k;
  vector<int> x(m),y(m);
  REP(i,m) { cin >> x[i] >> y[i]; x[i]--; y[i]--; }

  // dp[i][v] := i 回移動して v にいる場合の数
  // inline DP: O(n^2) だと大きすぎるため、一つの配列(今回はdeque)を使い回す
  deque<mint> dp(n);
  dp[0] = 1;
  REP(ki,k) {
    // 遷移前の値
    vector<mint> val(m);
    REP(i,m) val[i] = dp[x[i]];
    // 一つずらすことで同じ配列を使い回す
    dp.push_front(dp.back());
    dp.pop_back();
    REP(i,m) dp[y[i]] += val[i];
  }

  mint ans;
  REP(i,n) ans += dp[i];
  cout << ans.val() << endl;
  return 0;
}