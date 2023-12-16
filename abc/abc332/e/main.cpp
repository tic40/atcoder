#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
template<class T> void chmin(T& a, T b) { a = min(a,b); }

int main() {
  int n,d; cin >> n >> d;
  vector<double> w(n);
  REP(i,n) cin >> w[i];
  int n2 = 1<<n;
  double ave = accumulate(w.begin(),w.end(),0.0) / d;

  vector<double> x(n2);
  REP(s,n2) {
    REP(i,n) if (s>>i & 1) x[s] += w[i];
    x[s] = (x[s] - ave) * (x[s] - ave);
  }

  const double INF = 1e18;
  // bit DP
  // dp[i][s] := i 袋作って残りが s であるときの min
  vector<double> dp(n2,INF);
  dp[n2-1] = 0;
  REP(i,d) {
    vector<double> old(n2,INF);
    swap(dp,old);
    REP(s,n2) {
      // 部分集合をループ
      for(int t = s;; t = (t-1)&s) {
        chmin(dp[s^t], old[s]+x[t]);
        if (t == 0) break;
      }
    }
  }
  double ans = dp[0]/d;
  printf("%.10f\n", ans);
  return 0;
}