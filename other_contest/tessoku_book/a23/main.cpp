#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
const int INF = numeric_limits<int>::max();

int main() {
  int n,m; cin >> n >> m;
  vector a(m,vector<int>(n));
  REP(i,m) REP(j,n) cin >> a[i][j];

  vector<int> dp(1<<n,INF);
  dp[0] = 0;
  REP(bit,1<<n) {
    if (dp[bit] == INF) continue;
    REP(i,m) {
      int nbit = bit;
      REP(j,n) if (a[i][j]) nbit += 1<<j;
      dp[nbit] = min(dp[nbit], dp[bit]+1);
    }
  }

  int ans = dp[(1<<n)-1];
  cout << (ans == INF ? -1 : ans) << endl;
  return 0;
}