#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int a,b,c; cin >> a >> b >> c;
  // dp[i][j][k] := 金i枚,銀j枚,銅k枚ある状態からゴールするまでの回数の期待値
  vector dp(101,vector(101,vector<double>(101)));

  for(int i = 99; i >= a; i--) {
    for(int j = 99; j >= b; j--) {
      for(int k = 99; k >= c; k--) {
        if (i+j+k == 0) continue;
        double now = 1;
        now += dp[i+1][j][k] * (double)i/(i+j+k);
        now += dp[i][j+1][k] * (double)j/(i+j+k);
        now += dp[i][j][k+1] * (double)k/(i+j+k);
        dp[i][j][k] = now;
      }
    }
  }

  printf("%.10f\n",dp[a][b][c]);
  return 0;
}