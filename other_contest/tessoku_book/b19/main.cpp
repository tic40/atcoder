#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n,W; cin >> n >> W;
  vector<int> w(n),v(n);
  REP(i,n) cin >> w[i] >> v[i];

  vector<int> dp(1e5+1,1e9+1);
  dp[0] = 0;
  REP(i,n) {
    vector<int> p(1e5+1);
    swap(dp,p);
    REP(j,1e5+1) {
      dp[j] = p[j];
      if (j-v[i] >= 0) dp[j] = min(dp[j], p[j-v[i]]+w[i]);
    }
  }

  for(int i = 1e5; i >= 0; i--) {
    if (dp[i] <= W) {
      cout << i << endl;
      break;
    }
  }
  return 0;
}