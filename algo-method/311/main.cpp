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

  vector<int> dp(m+1, INF);
  dp[0] = 0;

  REP(i,n) for (int j = m+1; 0 <= j; j--) {
    int ni = a[i]+j;
    if (ni <= m && dp[j] != INF) {
      dp[ni] = min(dp[ni], dp[j]+1);
    }
  }

  cout << (dp[m] == INF ? -1 : dp[m]) << endl;
  return 0;
}