#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
void chmax(int& a, int b) { a = max(a,b); }

int main() {
  int n; cin >> n;
  vector d(n,vector<int>(3));
  REP(i,n) cin >> d[i][0] >> d[i][1] >> d[i][2];

  vector dp(n+1, vector<int>(3));
  REP(i,n) REP(from,3) REP(to,3) if (from != to) {
    chmax(dp[i+1][to], dp[i][from] + d[i][to]);
  }

  cout << max({dp[n][0],dp[n][1],dp[n][2]}) << endl;
  return 0;
}
