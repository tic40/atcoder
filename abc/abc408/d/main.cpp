#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int t; cin >> t;
  REP(_,t) {
    int n; string s; cin >> n >> s;
    // dp[i][j] := i まで決めたとき、末尾の値が j のときの最小コスト
    vector dp(n+1,vector<int>(3,1e9));
    dp[0][0] = 0;
    REP(i,n) REP(j,3) REP(pj,j+1) {
      int cost = s[i]-'0' == j%2 ? 0 : 1;
      dp[i+1][j] = min(dp[i+1][j], dp[i][pj] + cost);
    }
    cout << *min_element(dp[n].begin(),dp[n].end()) << endl;
  }
  return 0;
}