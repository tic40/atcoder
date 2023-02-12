#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
template<class T> void chmax(T& a, T b) { if (a < b) a = b; }

int main() {
  int n; cin >> n;
  vector<int> p(n),a(n);
  REP(i,n) { cin >> p[i] >> a[i]; p[i]--; }

  vector dp(n, vector<int>(n));
  for(int len = n-1; len > 0; len--) REP(l,n-len) {
    int r = l+len, s1 = 0, s2 = 0;

    // lのブロックを取り除く
    if (l <= p[l] && p[l] <= r) s1 = a[l];
    // rのブロックを取り除く
    if (l <= p[r] && p[r] <= r) s2 = a[r];

    if (l+1 <= r) chmax(dp[l+1][r],dp[l][r] + s1);
    if (l <= r-1) chmax(dp[l][r-1],dp[l][r] + s2);
  }

  int ans = 0;
  REP(i,n) ans = max(ans,dp[i][i]);
  cout << ans << endl;
  return 0;
}