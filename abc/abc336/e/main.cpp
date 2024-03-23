#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;

// dp[i][j][s][r]
// i: 何桁まで決めたか
// j: 以下フラグ. 1: N以下が確定, 0: 確定していない
// s: 桁和
// r: 桁和をkで割った余り
ll dp[16][2][130][130];

int main() {
  ll n; cin >> n;
  n++; // 簡単にするため、+1 して n 未満を数える問題にする

  // n の各桁の値を直接参照できるようにする
  vector<int> digit;
  while(n) {
    digit.push_back(n%10);
    n/=10;
  }
  reverse(digit.begin(),digit.end());
  int m = digit.size(); // 桁数

  ll ans = 0;
  // k: 桁和
  for(int k = 1; k < 129; k++) {
    // dp の初期化
    REP(i,m+1) REP(j,2) REP(s,k+1) REP(r,k) dp[i][j][s][r] = 0;
    dp[0][0][0][0] = 1;

    REP(i,m) REP(j,2) REP(s,k+1) REP(r,k) {
      REP(d,10) {
        int ni = i+1; // 次の桁
        int nj = j; // 以下フラグ
        int ns = s+d; // 桁和
        int nr = (r*10+d)%k; // kで割った余り
        if (ns > k) continue;
        if (j == 0) {
          if (digit[i] < d) continue;
          if (digit[i] > d) nj = 1;
        }

        dp[ni][nj][ns][nr] += dp[i][j][s][r];
      }
    }
    ans += dp[m][1][k][0];
  }

  cout << ans << endl;
  return 0;
}