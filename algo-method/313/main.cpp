#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
const int INF = 1e9;

// i 番目までの整数の中から選んで総和を j とするときの、選んだ A[i] の個数の最小値
int dp[505][10005];

int main() {
  int n,m;
  cin >> n >> m;
  vector<int> a(n),b(n);
  REP(i,n) cin >> a[i] >> b[i];

  REP(i,n+1) REP(j,m+1) dp[i][j] = INF;
  dp[0][0]=true;

  REP(i,n) REP(j,m+1) {
    // a[i]を選ばないケース
    if (dp[i][j] < INF) dp[i+1][j] = 0;
    if (j-a[i] < 0) continue;

    // a[i]を一度選べばいいケース
    if (dp[i][j-a[i]] < INF) {
      dp[i+1][j] = min(dp[i+1][j], 1);
    }
    // a[i]を複数選ぶケース
    if (dp[i+1][j-a[i]] < b[i]) {
      dp[i+1][j] = min(dp[i+1][j], dp[i+1][j-a[i]] + 1);
    }
  }

  cout << (dp[n][m] < INF ? "Yes" : "No") << endl;
  return 0;
}