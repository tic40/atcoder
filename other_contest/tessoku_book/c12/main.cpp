#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
template<class T> void chmax(T &a, T b) { a = max(a,b); }

int main() {
  int n,m,k; cin >> n >> m >> k;
  vector<int> a(m),b(m);
  REP(i,m) cin >> a[i] >> b[i];

  auto score = [&](int l, int r) {
    int cnt = 0;
    REP(i,m) if (l <= a[i] && b[i] <= r) cnt++;
    return cnt;
  };

  vector dp(k+1,vector<int>(n+1,-1e9));
  dp[0][0] = 0;
  REP(i,k) REP(j,n+1) REP(l,j) {
    chmax(dp[i+1][j], dp[i][l] + score(l+1,j));
  }

  cout << dp[k][n] << endl;
  return 0;
}