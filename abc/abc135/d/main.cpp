#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'
using mint = modint1000000007;

int main() {
  string s; cin >> s;
  int n = s.size();

  // 先頭 i 文字として考えられるもののうち，13 で割ったあまりが j であるものの数
  vector<mint> dp(13);
  dp[0] = 1;

  REP(i,n) {
    vector<mint> p(13);
    swap(dp,p);

    REP(j,13) {
      if (s[i] == '?') {
        REP(k,10) dp[ (j*10+k) % 13 ] += p[j];
      } else {
        dp[ (j*10+(s[i]-'0')) % 13 ] += p[j];
      }
    }
  }

  cout << dp[5].val() << endl;
  return 0;
}