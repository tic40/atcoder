#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)

bool dp[105][10005];

int main() {
  int n,a,b;
  cin >> n >> a >> b;
  vector<int> x(n);
  REP(i,n) cin >> x[i];

  dp[0][0]=true;
  REP(i,n) REP(j,a) {
    if (dp[i][j]) {
      dp[i+1][j] = true;
      dp[i+1][(j+x[i]) % a] = true;
    }
  }

  cout << (dp[n][b] ? "Yes" : "No") << endl;
  return 0;
}