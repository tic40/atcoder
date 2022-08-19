#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'

const int x = 100;

int main() {
  int a,b,c; cin >> a >> b >> c;

  vector dp(x+1, vector(x+1, vector<double>(x+1)));

  for(int i = x-1; i >= 0; i--) {
    for(int j = x-1; j >= 0; j--) {
      for(int k = x-1; k >= 0; k--) {
        if(i+j+k == 0) continue;
        double now = 0;
        now += dp[i+1][j][k] * i;
        now += dp[i][j+1][k] * j;
        now += dp[i][j][k+1] * k;
        dp[i][j][k] = now / (i+j+k) + 1;
      }
    }
  }

  printf("%0.10f\n",dp[a][b][c]);
  return 0;
}