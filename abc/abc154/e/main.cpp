#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
typedef long long ll;

int dp[105][4][2];

int main() {
  string s; cin >> s;
  int n = s.size();
  int K; cin >> K;

  dp[0][0][0] = 1;
  // i: i桁目まで
  // j: j個の非0を使って
  // k: 0: そこまでの桁はNと一致
  //    1: そこまでの桁ですでにN未満であることが確定
  REP(i,n) REP(j,4) REP(k,2) {
    int nd = s[i]-'0';
    REP(d,10) {
      int ni = i+1, nj = j, nk = k;
      if (d != 0) nj++;
      if (nj > K) continue;
      if (k == 0) {
        if (d > nd) continue;
        if (d < nd) nk = 1;
      }
      dp[ni][nj][nk] += dp[i][j][k];
    }
  }
  int ans = dp[n][K][0] + dp[n][K][1];
  cout << ans << endl;
}