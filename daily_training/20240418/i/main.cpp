#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;
using mint = modint998244353; // modint1000000007;

int main() {
  string s; cin >> s;
  int n = s.size();
  mint ans = 0;

  int m = 26;
  vector nxt(m,vector<int>(n));
  REP(c,m) {
    int p = n;
    for(int i = n-1; i >= 0; i--) {
      if (s[i] == 'a'+c) p = i;
      nxt[c][i] = p;
    }
  }

  for(int k = 1; k < n; k++) {
    vector dp(n+1,vector<mint>(n+1));
    dp[0][k] = 1;
    REP(i,k) for(int j = k; j < n; j++) {
      REP(c,m) {
        int ni = nxt[c][i]+1, nj = nxt[c][j]+1;
        if (ni > k || nj > n) continue;
        dp[ni][nj] += dp[i][j];
      }
    }
    for(int j = k; j <= n; j++) ans += dp[k][j];
  }

  cout << ans.val() << endl;
  return 0;
}