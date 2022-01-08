#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<(int)(n);i++)

int dp[105][105];

int main() {
  int h,w;
  cin >> h >> w;
  vector<string> s(h);
  REP(i,h) cin >> s[i];

  for(int i = h-1; 0 <= i; i--) {
    for(int j = w-1; 0 <= j; j--) {
      if (s[i][j] == '#') {
        dp[i][j] = 0;
        continue;
      }

      dp[i][j] = 1 + max(dp[i+1][j], dp[i][j+1]);
    }
  }

  cout << dp[0][0] << endl;
  return 0;
}