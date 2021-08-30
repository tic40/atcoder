#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
using ll = long long;
const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;

bool dp[105][10005];
int main() {
  int n,m;
  cin >> n >> m;
  vector<int> a(n-1);
  REP(i,n-1) cin >> a[i];

  dp[0][0]=true; // 初期位置
  REP(i,n) {
    REP(j,m) {
      dp[i+1][j] = dp[i+1][j] || dp[i][j];
      if (j+a[i] < m) dp[i+1][j+a[i]] = dp[i+1][j+a[i]] || dp[i][j];
    }
  }

  int ans = 0;
  REP(i,m) ans += dp[n-1][i];
  cout << ans << endl;
  return 0;
}