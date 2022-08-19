#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'

/*
  dp[i][j][k]
  3個の寿司が乗っている皿がi個
  2個の寿司が乗っている皿がj個
  1個の寿司が乗っている皿がk個
  のときのすべての寿司がなくなるまでの操作回数
*/
double dp[301][301][301];

int main() {
  int n; cin >> n;
  vector<int> a(n);
  REP(i,n) cin >> a[i];
  vector<int> m(4);
  REP(i,n) m[a[i]]++;

  REP(i,301) REP(j,301) REP(k,301) {
    if (i+j+k == 0) continue;
    dp[i][j][k] += (double)n / (i+j+k);
    if (i > 0) dp[i][j][k] += dp[i-1][j+1][k] * i / (i+j+k);
    if (j > 0) dp[i][j][k] += dp[i][j-1][k+1] * j / (i+j+k);
    if (k > 0) dp[i][j][k] += dp[i][j][k-1] * k / (i+j+k);
  }

  double ans = dp[m[3]][m[2]][m[1]];
  printf("%.10f\n", ans);
  return 0;
}