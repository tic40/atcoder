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

  // m[i][j] := jがそれぞれの状態の総数. 1: A, 2: AB, 3: ABC
  vector<mint> dp(4);
  dp[0] = 1;
  REP(i,n) {
    vector<mint> p(4);
    swap(dp,p);
    REP(j,4) dp[j] += s[i] == '?' ? p[j]*3 : p[j];

    if (s[i] == 'A' || s[i] == '?') dp[1] += p[0];
    if (s[i] == 'B' || s[i] == '?') dp[2] += p[1];
    if (s[i] == 'C' || s[i] == '?') dp[3] += p[2];
  }

  cout << dp[3].val() << endl;
  return 0;
}