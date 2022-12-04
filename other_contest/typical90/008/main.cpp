#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'
using mint = modint1000000007;

const string atc = " atcoder";

int main() {
  int n; string s;
  cin >> n >> s;

  vector<mint> dp(8);
  dp[0] = 1;
  REP(i,n) {
    vector<mint> p(8);
    swap(dp,p);
    REP(j,8) {
      dp[j] += p[j];
      if (s[i] == atc[j]) dp[j] += p[j-1];
    }
  }

  cout << dp[7].val() << endl;
  return 0;
}