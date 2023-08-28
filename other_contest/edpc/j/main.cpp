#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'

int main() {
  int n; cin >> n;
  vector<int> a(n);
  REP(i,n) cin >> a[i];

  /*
    dp[i][j][k]
    3個の寿司が乗っている皿がi個
    2個の寿司が乗っている皿がj個
    1個の寿司が乗っている皿がk個
    のときのすべての寿司がなくなるまでの操作回数
  */
  vector dp(n+2,vector(n+2,vector<double>(n+2)));

  REP(i,n+1) REP(j,n+1) REP(k,n+1) {
    double tot = i+j+k;
    if (tot == 0) continue;

    // まずトータルの食べる回数を考える
    // サイコロは n 個の目がでる。
    // tot 枚の皿に寿司がのっているため、 p = tot / n の確率で寿司を食べられる。
    // このとき寿司を食べられる期待値は 1 / p のため n / tot
    dp[i][j][k] += n / tot;

    // i,j,k の状態から、それぞれを食べるケースを考える
    // 3個乗っている皿の寿司を食べると dp[i-1][j+1][k] へ遷移
    if (i > 0) dp[i][j][k] += dp[i-1][j+1][k] * i / tot;
    if (j > 0) dp[i][j][k] += dp[i][j-1][k+1] * j / tot;
    if (k > 0) dp[i][j][k] += dp[i][j][k-1] * k / tot;
  }

  vector<int> m(4);
  REP(i,n) m[a[i]]++;
  printf("%.10f\n", dp[m[3]][m[2]][m[1]]);
  return 0;
}