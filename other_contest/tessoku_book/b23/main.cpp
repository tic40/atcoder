#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
const int INF = numeric_limits<int>::max();
template<class T> void chmin(T& a, T b) { if (a > b) a = b; }

int main() {
  int n; cin >> n;
  vector<int> x(n),y(n);
  REP(i,n) cin >> x[i] >> y[i];

  auto f = [&](int i, int j) {
    return sqrt(pow(x[i]-x[j],2) + pow(y[i]-y[j],2));
  };

  vector dp(1<<n,vector<double>(n,INF));
  REP(i,n) dp[0][0] = 0;
  REP(bit,1<<n) REP(i,n) {
    if (dp[bit][i] == INF) continue;
    REP(j,n) chmin(dp[bit|(1<<j)][j], dp[bit][i]+f(i,j));
  }

  printf("%.10f\n",dp[(1<<n)-1][0]);
  return 0;
}