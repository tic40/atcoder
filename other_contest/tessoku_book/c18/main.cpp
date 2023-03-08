#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'
const int INF = 1e9;
template<class T> void chmin(T& a, T b) { a = min(a,b); }

int main() {
  int n; cin >> n;
  n*=2;
  vector<int> a(n);
  REP(i,n) cin >> a[i];

  // dp[i][j] := 範囲 i から j を削除するときの最小コスト
  vector dp(n,vector<int>(n,INF));
  REP(i,n-1) dp[i][i+1] = abs(a[i+1]-a[i]);

  for(int i = 3; i < n; i+=2) REP(j,n-i) {
    int l = j, r = j+i;
    chmin(dp[l][r], abs(a[l]-a[r]) + dp[l+1][r-1]);
    for(int k = l; k < r; k++) chmin(dp[l][r], dp[l][k]+dp[k+1][r]);
  }

  cout << dp[0][n-1] << endl;
  return 0;
}