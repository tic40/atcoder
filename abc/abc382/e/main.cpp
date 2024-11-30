#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n,x; cin >> n >> x;
  vector<double> p(n);
  REP(i,n) cin >> p[i], p[i] /= 100.0;

  // dp[i][j] := i 枚目までで レアカードを j 枚持つ確率
  vector<double> dp(n+1);
  dp[0] = 1.0; // レアカード 0 枚は 100 %
  REP(i,n) {
    vector<double> prev(n+1);
    swap(dp,prev);
    REP(j,i+1) {
      dp[j] += prev[j] * (1.0 - p[i]); // レアカードが出ない
      dp[j+1] += prev[j] * p[i]; // レアカードが出る
    }
  }

  // f[i] := レアカードが x 枚になるまで必要なパック数の期待値
  vector<double> f(x+1);
  for(int i = 1; i <= x; i++) {
    double sum = 0;
    REP(j,n+1) {
      if (i-j <= 0) break;
      sum += dp[j] * f[i-j];
    }
    sum += 1.0;
    // f[i] = dp[0] * f[i] + sum
    // f[i] = sum / (1 - dp[0])
    f[i] = sum / (1.0 - dp[0]);
  }

  printf("%.10f\n", f[x]);
  return 0;
}