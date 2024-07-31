#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
const int INF = numeric_limits<int>::max();
template<class T> void chmin(T& a, T b) { a = min(a,b); }

int main() {
  int n,x,y; cin >> n >> x >> y;
  vector<int> a(n),b(n);
  REP(i,n) cin >> a[i] >> b[i];

  // dp[i][j] :=  甘さが i で、個数が j のときのしょっぱさの最小値
  // 甘さ x しょっぱさ = 個数で DP テーブルを持つと n * x * y = 8e9 となり大きすぎる
  // 甘さ x 個数 = しょっぱさで DP テーブルを持つと n * x * n = 80^2 * 1000 = 6e5 で済む
  vector dp(x+1,vector<int>(n+1,INF));
  dp[0][0] = 0;

  REP(i,n) {
    vector old(x+1,vector<int>(n+1,INF));
    swap(dp,old);
    REP(j,x+1) REP(k,n+1) {
      int now = old[j][k];
      if (now == INF) continue;
      chmin(dp[j][k],old[j][k]);
      if (j+a[i] <= x) chmin(dp[j+a[i]][k+1],now+b[i]);
    }
  }

  int ans = 0;
  REP(j,x+1) REP(k,n+1) if (dp[j][k] <= y) ans = max(ans,k);
  if (ans < n) ans++;
  cout << ans << endl;
  return 0;
}