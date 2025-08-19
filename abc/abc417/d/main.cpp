#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n; cin >> n;
  vector<int> p(n),a(n),b(n);
  REP(i,n) cin >> p[i] >> a[i] >> b[i];
  const int m = 1001;
  // dp[i][j] := i までもらってテンションが j のときの最終的なテンションの値
  vector dp(n+1,vector<int>(m));
  REP(i,m) dp[n][i] = i;
  for(int i = n-1; i >= 0; i--) REP(j,m) {
    int nj = j <= p[i] ? j+a[i] : max(0,j-b[i]);
    dp[i][j] = dp[i+1][nj];
  }

  vector<int> bs(n+1);
  REP(i,n) bs[i+1] = bs[i]+b[i];

  int q; cin >> q;
  REP(_,q) {
    int x; cin >> x;
    if (x >= m) {
      int idx = upper_bound(bs.begin(),bs.begin()+n,x-m) - bs.begin();
      x -= bs[idx];
      cout << (idx < n ? dp[idx][x] : x) << endl;
    } else {
      cout << dp[0][x] << endl;
    }
  }
  return 0;
}