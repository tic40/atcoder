#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
const int INF = numeric_limits<int>::max();

int main() {
  int n; cin >> n;
  vector<int> h(n);
  REP(i,n) cin >> h[i];

  vector<int> dp(n,INF);
  dp[0] = 0;
  REP(i,n) {
    if (i-1 >= 0) dp[i] = min(dp[i], dp[i-1]+ abs(h[i]-h[i-1]));
    if (i-2 >= 0) dp[i] = min(dp[i], dp[i-2]+ abs(h[i]-h[i-2]));
  }

  cout << dp[n-1] << endl;
  return 0;
}