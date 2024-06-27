#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using mint = modint1000000007;

int main() {
  int h,w; cin >> h >> w;
  vector<string> a(h);
  REP(i,h) cin >> a[i];
  REP(i,h) a[i] += '.';
  a.push_back(string(w+1,'.'));

  vector dp(h+1,vector<mint>(w+1));
  dp[0][0] = 1;
  REP(i,h) REP(j,w) if (a[i][j] == '.') {
    dp[i+1][j] += dp[i][j];
    dp[i][j+1] += dp[i][j];
  }

  cout << dp[h-1][w-1].val() << endl;
  return 0;
}