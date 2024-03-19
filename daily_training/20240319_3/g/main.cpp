#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;
template<class T> void chmax(T& a, T b) { a = max(a,b); }

int main() {
  int n,k,d; cin >> n >> k >> d;
  vector<int> a(n);
  REP(i,n) cin >> a[i];

  // dp[i][j][k] := i まで見たときに j 個使ったときあまりが d になるときの最大値
  vector dp(n+1,vector(k+2,vector<ll>(d,-1)));
  dp[0][0][0] = 0;
  REP(i,n) REP(j,k+1) REP(l,d) {
    if (dp[i][j][l] == -1) continue;
    // 選ばない
    chmax(dp[i+1][j][l], dp[i][j][l]);
    // 選ぶ
    chmax(dp[i+1][j+1][ (l+a[i]) % d], dp[i][j][l] + a[i]);
  }

  cout << dp[n][k][0] << endl;
  return 0;
}