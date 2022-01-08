#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
using ll = long long;

int a,b;
ll k;
ll dp[31][31]; // [i][j] := aをi個、bをj個使ったときの総数

void solve() {
  // 前計算する
  dp[0][0] = 1;
  REP(i,a+1) REP(j,b+1) {
    if (i > 0) dp[i][j] += dp[i-1][j];
    if (j > 0) dp[i][j] += dp[i][j-1];
  }

  string ans;
  while(a+b > 0) {
    if (0 < a) {
      if (k <= dp[a-1][b]) {
        ans += 'a';
        a--;
      } else {
        ans += 'b';
        k -= dp[a-1][b];
        b--;
      }
    } else {
      ans += 'b';
      b--;
    }
  }

  cout << ans << endl;
  return;
}

int main() {
  cin >> a >> b >> k;

  solve();
  return 0;
}