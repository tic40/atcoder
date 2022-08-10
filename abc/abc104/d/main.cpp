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

  // "", A, AB, ABC それぞれの状態の総数
  vector<mint> dp(4);
  dp[0] = 1;
  REP(i,n) {
    vector<mint> p(4);
    swap(dp,p);

    // ABCの要素を選ばない
    REP(j,4) dp[j] += s[i] == '?' ? p[j]*3 : p[j];

    // 選ぶ
    if (s[i] == 'A') dp[1] += p[0];
    if (s[i] == 'B') dp[2] += p[1];
    if (s[i] == 'C') dp[3] += p[2];
    if (s[i] == '?') {
      dp[1] += p[0];
      dp[2] += p[1];
      dp[3] += p[2];
    }
  }

  cout << dp[3].val() << endl;
  return 0;
}