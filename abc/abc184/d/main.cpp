#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'

const int x = 100;

int main() {
  int a,b,c; cin >> a >> b >> c;
  // dp[i][j][k] := 金i枚,銀j枚,銅k枚ある状態からの期待値
  vector dp(x+1, vector(x+1, vector<double>(x+1)));

  for(int i = x-1; i >= 0; i--) {
    for(int j = x-1; j >= 0; j--) {
      for(int k = x-1; k >= 0; k--) {
        if(i+j+k == 0) continue;
        // i+j+k の中から一枚取ることを考える
        dp[i][j][k] += (dp[i+1][j][k]+1) * i / (i+j+k);
        dp[i][j][k] += (dp[i][j+1][k]+1) * j / (i+j+k);
        dp[i][j][k] += (dp[i][j][k+1]+1) * k / (i+j+k);
      }
    }
  }

  printf("%0.10f\n",dp[a][b][c]);
  return 0;
}