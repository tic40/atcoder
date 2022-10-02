#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'
using mint = modint1000000007;

int main() {
  int n; string s;
  cin >> n >> s;
  const string t = "atcoder";

  vector<mint> dp(8);
  dp[0] = 1;
  REP(i,n) {
    vector<mint> p(8);
    p[0] = 1;
    swap(dp,p);
    REP(j,7) {
      dp[j+1] = p[j+1];
      if (s[i] == t[j]) dp[j+1] += p[j];
    }
  }

  cout << dp[7].val() << endl;
  return 0;
}