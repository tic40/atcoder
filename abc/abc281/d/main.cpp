#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;
template<class T> void chmax(T& a, T b) { if (a < b) a = b; }

int main() {
  int n,k,d; cin >> n >> k >> d;
  vector<int> a(n);
  REP(i,n) cin >> a[i];

  vector dp(n+1, vector(d+1, vector<ll>(k+2, -1)));
  dp[0][0][0] = 0;

  REP(i,n) REP(j,d) REP(l,k+1) {
    if (dp[i][j][l] == -1) continue;
    chmax(dp[i+1][j][l], dp[i][j][l]);
    chmax(dp[i+1][(j+a[i])%d][l+1], dp[i][j][l] + a[i]);
  }

  cout << dp[n][0][k] << endl;
  return 0;
}