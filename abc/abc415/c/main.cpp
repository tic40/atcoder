#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  auto solve = []() -> bool {
    int n; string s;
    cin >> n >> s;
    s = '0'+s;

    vector<int> dp(1<<n);
    dp[0] = 1;
    REP(bit,1<<n) if(dp[bit]) {
      REP(j,n) {
        int nbit = bit|(1<<j);
        if (s[nbit] == '0') dp[nbit] = 1;
      }
    }
    return dp[(1<<n)-1];
  };

  int t; cin >> t;
  REP(_,t) cout << (solve() ? "Yes" : "No") << endl;
  return 0;
}