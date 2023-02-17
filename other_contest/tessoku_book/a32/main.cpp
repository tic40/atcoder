#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n,a,b; cin >> n >> a >> b;
  // 山に n 個の石があるとき先手が勝つかどうか
  vector<bool> dp(n+1);
  REP(i,n+1) {
    if (i-a >= 0 && !dp[i-a]) dp[i] = true;
    if (i-b >= 0 && !dp[i-b]) dp[i] = true;
  }

  cout << (dp[n] ? "First" : "Second") << endl;
  return 0;
}