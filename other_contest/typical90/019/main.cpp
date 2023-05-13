#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(int)(n);i++)
const int INF = 1e9;
template<class T> void chmin(T& a, T b) { if (a > b) a = b; }

int main() {
  int n; cin >> n;
  n *= 2;
  vector<int> a(n);
  REP(i,n) cin >> a[i];

  // dp[l][r] := l 〜 r 番目の人が抜けるのに必要な最小のコスト
  vector dp(n,vector<int>(n,INF));
  REP(i,n-1) dp[i][i+1] = abs(a[i]-a[i+1]);

  for (int i = 3; i < n; i+=2) REP(j,n-i) {
    int l = j, r = j+i;
    // 最後に人l,rが抜けるケース
    chmin(dp[l][r], dp[l+1][r-1] + abs(a[l]-a[r]));
    // それ以外のケース: [l,k] の区間と [k+1,r] に分けて考える
    REP(k,i) chmin(dp[l][r], dp[l][l+k] + dp[l+k+1][r]);
  }

  cout << dp[0][n-1] << endl;
  return 0;
}