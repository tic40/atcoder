#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
using ll = long long;
const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;

int n;
string s;
bool dp[30005][4][1000];

int main() {
  cin >> n >> s;

  dp[0][0][0] = true;

  REP(i,n) REP(j,4) REP(k,1000) {
    if (!dp[i][j][k]) continue;
    dp[i+1][j][k] = true;
    if (j <= 2) {
      int x = k*10+s[i]-'0';
      if (0 <= x && x <= 999) {
        dp[i+1][j+1][k*10+s[i]-'0'] = true;
      }
    }
  }

  int ans = 0;
  REP(k,1000) if (dp[n][3][k]) ans++;
  cout << ans << endl;
  return 0;
}