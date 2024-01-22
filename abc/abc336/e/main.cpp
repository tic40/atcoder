#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;

// dp[i][j][s][r]
// i: 何桁まで決めたか
// j: 以下フラグ. 1ならばN未満, 0: 何でもok
// s: 桁和
// r: kで割った余り
ll dp[16][2][130][130];

int main() {
  ll n; cin >> n;
  n++;

  vector<int> digit;
  while(n) {
    digit.push_back(n%10);
    n/=10;
  }
  reverse(digit.begin(),digit.end());
  int m = digit.size(); // 桁数

  ll ans = 0;
  for(int k = 1; k <= 126; k++) {
    // 初期化
    REP(i,m+1) REP(j,2) REP(s,k+1) REP(r,k) dp[i][j][s][r] = 0;
    dp[0][0][0][0] = 1;

    REP(i,m) REP(j,2) REP(s,k+1) REP(r,k) {
      REP(d,10) {
        int ni = i+1;
        int nj = j;
        int ns = s+d;
        int nr = (r*10+d)%k;
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