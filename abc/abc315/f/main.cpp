#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
const int INF = numeric_limits<int>::max();
template<class T> void chmin(T &a, T b) { a = min(a,b); }

int main() {
  int n; cin >> n;
  vector<double> x(n),y(n);
  REP(i,n) cin >> x[i] >> y[i];

  auto dist = [&](int i, int j) {
    double a = x[j]-x[i];
    double b = y[j]-y[i];
    return sqrt(a*a+b*b);
  };

  // ペナルティの上限. C = 20
  // 座標の max は 10^4 のため、2点間の最大距離は sqrt(10^4*2)
  // スキップしないときの最大値は sqrt(10^4*2) * 10^4
  const int m = 20;
  // dp[最後に通ったチェックポイント][無視したチェックポイントの数] = 距離の総和の最小値
  vector dp(n,vector<double>(m,INF));
  dp[0][0] = 0;
  REP(i,n) REP(j,m) REP(k,n) {
    int ni = i+1+k;
    int nj = j+k;
    if (ni >= n || nj >= m) break;
    chmin(dp[ni][nj], dp[i][j] + dist(i,ni));
  }

  double ans = INF;
  REP(j,m) chmin(ans,dp[n-1][j] + (1<<j>>1));
  printf("%.10f\n",ans);
  return 0;
}