#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
const int MOD = 1e9+7;

// dp[pos][atcoderの何文字目まで] = 通り数
int dp[100005][8];

int main() {
  int n; cin >> n;
  string s; cin >> s;

  dp[0][0]=1;
  REP(i,n) {
    char cur = s[i];
    REP(j,8) {
      dp[i+1][j] += dp[i][j];
			if (cur=='a' && j==0) dp[i+1][j+1] += dp[i][j];
			if (cur=='t' && j==1) dp[i+1][j+1] += dp[i][j];
			if (cur=='c' && j==2) dp[i+1][j+1] += dp[i][j];
			if (cur=='o' && j==3) dp[i+1][j+1] += dp[i][j];
			if (cur=='d' && j==4) dp[i+1][j+1] += dp[i][j];
			if (cur=='e' && j==5) dp[i+1][j+1] += dp[i][j];
			if (cur=='r' && j==6) dp[i+1][j+1] += dp[i][j];
    }
    REP(j,8) dp[i+1][j]%=MOD;
  }

  cout << dp[n][7] << endl;
  return 0;
}