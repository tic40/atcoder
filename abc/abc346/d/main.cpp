#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;
const ll LINF = numeric_limits<ll>::max();
template<class T> void chmin(T& a, T b) { a = min(a,b); }

int main() {
  int n; cin >> n;
  string s; cin >> s;
  vector<int> c(n);
  REP(i,n) cin >> c[i];
  vector<int> si(n);
  REP(i,n) si[i] = s[i]-'0';

  // dp[i][j][k]
  // i: 何文字目までみたか
  // j: 良い文字列フラグ
  // k: 最後の文字 0 or 1
  vector dp(n+1,vector(2,vector<ll>(2,LINF)));
  dp[1][0][si[0]] = 0;
  dp[1][0][si[0]^1] = c[0];

  auto f = [&](int i, int j, int k, int now, int cost) {
    if (now == k && j == 0) chmin(dp[i+1][1][now], dp[i][j][k] + cost);
    if (now != k) chmin(dp[i+1][j][now], dp[i][j][k] + cost);
  };

  for(int i = 1; i < n; i++) REP(j,2) REP(k,2) {
    if (dp[i][j][k] == LINF) continue;
    f(i,j,k,si[i],0); // 操作しない
    f(i,j,k,si[i]^1,c[i]); // 操作する
  }

  ll ans = min(dp[n][1][0], dp[n][1][1]);
  cout << ans << endl;
  return 0;
}