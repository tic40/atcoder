#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
template<class T> void chmin(T& a, T b) { a = min(a,b); }

// TODO: 復習
int main() {
  int n,d; cin >> n >> d;
  vector<double> w(n);
  REP(i,n) cin >> w[i];
  int n2 = 1<<n;
  double ave = accumulate(w.begin(),w.end(),0.0) / d;

  // 各状態(bit)での分散を事前に求めておく
  vector<double> x(n2);
  REP(bit,n2) {
    REP(i,n) if (bit >> i & 1) x[bit] += w[i];
    x[bit] = (x[bit] - ave) * (x[bit] - ave);
  }

  const double INF = 1e18;
  // bit DP
  // dp[i][bit] := i 袋作って残りが bit であるときの min
  vector<double> dp(n2,INF);
  dp[n2-1] = 0;
  REP(i,d) {
    vector<double> old(n2,INF);
    swap(dp,old);
    REP(bit,n2) {
      // 部分集合をループ
      // 例:
      // 現在bit:  1011
      // 部分集合t: 1010
      // bit ^ t:  0001
      for(int t = bit; t > 0; t = (t-1) & bit) {
        chmin(dp[bit ^ t], old[bit] + x[t]);
      }
    }
  }
  double ans = dp[0]/d;
  printf("%.10f\n", ans);
  return 0;
}