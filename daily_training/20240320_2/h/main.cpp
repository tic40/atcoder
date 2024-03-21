#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;
const int INF = numeric_limits<int>::max();
template<class T> void chmax(T& a, T b) { a = max(a,b); }

int main() {
  int n; cin >> n;
  vector<int> p(n);
  REP(i,n) cin >> p[i];

  // dp[i][j] := i 個までみたときに j 個選んだときの最大値
  vector dp(n+1, vector<double>(n+1,-INF));
  dp[0][0] = 0;
  REP(i,n) REP(j,i+1) {
    if (dp[i][j] == -INF) continue;
    chmax(dp[i+1][j], dp[i][j]);
    chmax(dp[i+1][j+1], dp[i][j] * 0.9 + p[i]);
  }

  double ans = -INF;
  double y = 1;
  for(int i = 1; i <= n; i++) {
    chmax(ans,dp[n][i]/y - 1200/sqrt(i));
    y = y*0.9 + 1;
  }
  printf("%.10f\n", ans);
  return 0;
}