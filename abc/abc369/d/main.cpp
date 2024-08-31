#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;
const ll LINF = numeric_limits<ll>::max();
template<class T> void chmax(T& a, T b) { a = max(a,b); }

int main() {
  int n; cin >> n;
  vector<int> a(n);
  REP(i,n) cin >> a[i];

  // dp[i][j] := i 番目までみたとき、j=0 倒したのが偶数、j=1 倒したのが奇数回 のときの最大の経験値
  vector dp(n+1,vector<ll>(2,-LINF));
  dp[0][0] = 0;

  REP(i,n) {
    // 倒さない
    chmax(dp[i+1][0], dp[i][0]);
    chmax(dp[i+1][1], dp[i][1]);
    // 倒す
    chmax(dp[i+1][1], dp[i][0]+a[i]);
    chmax(dp[i+1][0], dp[i][1]+a[i]*2);
  }

  cout << max(dp[n][0],dp[n][1]) << endl;
  return 0;
}