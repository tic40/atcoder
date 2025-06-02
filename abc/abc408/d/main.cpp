#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
const int INF = 1e9;
template<class T> void chmin(T& a, T b) { a = min(a,b); }

int main() {
  auto solve = []() {
    int n; string s; cin >> n >> s;

    // dp[i][j] := i まで決めて、末尾を j にするときの最小コスト
    vector dp(n+1,vector<int>(3,INF));
    dp[0][0] = 0;
    REP(i,n) REP(j,3) {
      int cost = (s[i]-'0' == j%2) ? 0 : 1;
      REP(pj,j+1) chmin(dp[i+1][j],dp[i][pj]+cost);
    }
    cout << *min_element(dp[n].begin(),dp[n].end()) << endl;
  };

  int t; cin >> t;
  REP(_,t) solve();
  return 0;
}