#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
const int MOD = 1e5;
using ll = long long;

int main() {
  int n; ll k; cin >> n >> k;

  // doubling
  vector dp(61, vector<int>(1e5));
  REP(i,1e5) {
    string s = to_string(i);
    int sum = 0;
    for(auto c: s) sum += (c - '0');
    dp[0][i] = (i+sum) % MOD;
  }

  REP(i,60) REP(j,1e5) {
    dp[i+1][j] = dp[i][dp[i][j]];
  }

  int now = n;
  REP(i,61) if ((k >> i) & 1) now = dp[i][now];
  cout << now << endl;
  return 0;
}