#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
const int INF = 1e9;

int main() {
  int n,m;
  cin >> n >> m;
  vector<int> a(n);
  REP(i,n) cin >> a[i];

  vector<int> dp(n+1, INF);
  dp[0] = 0;
  REP(i,n) {
    for (int j = 1; j <= m; j++) {
      int ni = i+j;
      if (n <= ni) break;
      dp[ni] = min(dp[ni], dp[i] + a[ni] * j);
    }
  }

  cout << dp[n-1] << endl;
  return 0;
}