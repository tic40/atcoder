#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
using ll = long long;
const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;

int main() {
  int n,m;
  cin >> n >> m;
  vector<int> a(n);
  REP(i,n) cin >> a[i];

  vector<int> dp(m+1);
  dp[0]=1;

  REP(i,n) for (int j = m; j >= 0; j--) {
    int ni = j-a[i];
    if (ni >= 0 && dp[ni] > 0) {
      dp[j] += dp[ni];
      dp[j] %= 1000;
    }
  }

  cout << dp[m] << endl;
  return 0;
}