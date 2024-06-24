#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;
template<class T> void chmax(T& a, T b) { a = max(a,b); }

int main() {
  int n,W; cin >> n >> W;
  vector<int> w(n),v(n);
  REP(i,n) cin >> w[i] >> v[i];

  // dp[i][j] := i 個までで重さ j のときの最大の価値
  vector dp(n+1, vector<ll>(W+1));

  REP(i,n) REP(j,W+1) {
    chmax(dp[i+1][j],dp[i][j]);
    int nj = j + w[i];
    if (nj <= W) chmax(dp[i+1][nj],dp[i][j] + v[i]);
  }

  ll ans = *max_element(dp[n].begin(),dp[n].end());
  cout << ans << endl;
  return 0;
}