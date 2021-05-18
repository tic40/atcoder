#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
using ll = long long;
const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;

int k;
ll dp[100005]; // dp[各桁の数字の和] = 通りの数

ll solve() {
  // kが9の倍数ではない
  if (k % 9 != 0) {
    return 0;
  }

  dp[0]=1;
  for(int i = 1; i <= k; i++) {
    for (int j = 1; j <= min(i,9); j++) {
      dp[i] += dp[i-j];
      dp[i] %= MOD;
    }
  }

  return dp[k];
}

int main() {
  cin >> k;
  cout << solve() << endl;
  return 0;
}