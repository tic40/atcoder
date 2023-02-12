#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
template<class T> void chmax(T& a, T b) { if (a < b) a = b; }

int main() {
  int n; cin >> n;
  string s; cin >> s;

  vector dp(n,vector<int>(n));
  REP(i,n) dp[i][i] = 1;
  REP(i,n-1) dp[i][i+1] = (s[i] == s[i+1] ? 2 : 1);

  for(int len = 1; len < n; len++) REP(l,n-len) {
    int r = l+len;
    if (s[l] == s[r]) dp[l][r] = dp[l+1][r-1]+2;
    chmax(dp[l][r], max(dp[l][r-1],dp[l+1][r]));
  }

  cout << dp[0][n-1] << endl;
  return 0;
}