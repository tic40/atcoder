#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
using ll = long long;
const int INF = 1e9;
const int MOD = 1e9+7;

int n,l;
ll dp[100005];

void solve() {
  dp[0] = 1;

  REP(i,n+1) {
    if (i+1 <= n) {
      dp[i+1] += dp[i];
      dp[i+1] %= MOD;
    }
    if (i+l <= n) {
      dp[i+l] += dp[i];
      dp[i+l] %= MOD;
    }
  }

  cout << dp[n] << endl;
  return;
}

int main() {
  cin >> n >> l;
  solve();
  return 0;
}