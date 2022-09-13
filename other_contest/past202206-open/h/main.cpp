#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'
using ll = long long;

int main() {
  int n,a,b;
  cin >> n >> a >> b;

  // dp[i][j] := Aのナップサックにiの重さ以下、Bにjの重さ以下を入れたときの最大の価値
  vector dp(a+1, vector<ll>(b+1));
  REP(i,n) {
    int w,v; cin >> w >> v;
    vector p(a+1, vector<ll>(b+1));
    swap(dp,p);

    REP(i,a+1) {
      REP(j,b+1) {
        dp[i][j] = p[i][j];
        if (i-w >= 0) dp[i][j] = max(dp[i][j], p[i-w][j] + v);
        if (j-w >= 0) dp[i][j] = max(dp[i][j], p[i][j-w] + v);
      }
    }
  }

  cout << dp[a][b] << endl;
  return 0;
}