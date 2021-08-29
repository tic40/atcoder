#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
using ll = long long;
const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;

int dp[20][20];
int main() {
  int n; cin >> n;
  vector<string> s(n);
  REP(i,n) cin >> s[i];

  dp[0][0]=1;
  REP(i,n) REP(j,n) {
    if (s[i][j] == '#') continue;
    dp[i+1][j] += dp[i][j];
    dp[i][j+1] += dp[i][j];
  }

  cout << dp[n-1][n-1] << endl;
  return 0;
}