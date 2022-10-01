#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'

vector<int> a(100),b(100);
vector dp(101, vector<bool>(10001));
string ans;

void dfs(int i, int now, string str) {
  if (ans.size()) return;
  if (i == 0) {
    if (now == 0) ans = str;
    return;
  }

  int na = now - a[i-1];
  int nb = now - b[i-1];
  if (na >= 0 && dp[i-1][na]) dfs(i-1, na, "H" + str);
  if (nb >= 0 && dp[i-1][nb]) dfs(i-1, nb, "T" + str);
  return;
}

int main() {
  int n,s; cin >> n >> s;
  REP(i,n) cin >> a[i] >> b[i];

  dp[0][0] = true;
  REP(i,n) REP(j,s+1) {
    if (j - a[i] >= 0) dp[i+1][j] = dp[i+1][j] || dp[i][j - a[i]];
    if (j - b[i] >= 0) dp[i+1][j] = dp[i+1][j] || dp[i][j - b[i]];
  }

  if (dp[n][s]) {
    cout << "Yes" << endl;
    dfs(n, s, ""); // 経路復元
    cout << ans << endl;
  } else {
    cout << "No" << endl;
  }

  return 0;
}