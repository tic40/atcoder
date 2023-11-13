#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
template<class T> void chmax(T& a, T b) { a = max(a,b); }
const int INF = 1e9;

int main() {
  int n; cin >> n;
  vector<int> p(n);
  REP(i,n) cin >> p[i];

  // dp[i][j] := i まで見て j 個えらんだときの max
  vector dp(n+1,vector<double>(n+1,-INF));
  dp[0][0] = 0;

  REP(i,n) {
    for(int j = 0; j <= i; j++) {
      if (dp[i][j] == -INF) continue;
      chmax(dp[i+1][j], dp[i][j]);
      chmax(dp[i+1][j+1], dp[i][j] * 0.9 + p[i]);
    }
  }

  double ans = -INF;
  double x = 1;
  for(int j = 1; j <= n; j++) {
    double now = dp[n][j];
    now /= x;
    now -= 1200/sqrt(j);
    chmax(ans,now);
    x = x*0.9+1;
  }
  printf("%.10f\n",ans);
  return 0;
}