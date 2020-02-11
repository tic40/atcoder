#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
typedef long long ll;
const int INF = 1001001001;

int main() {
  int n; cin >> n;
  int h[n]; REP(i, n) cin >> h[i];

  int dp[n];
  REP(i,n+1) dp[i] = INF;
  dp[0] = 0;
  for (int i = 1; i < n; i++) {
    int h1 = dp[i-1] + abs(h[i-1]-h[i]);
    int h2 = i-2 >= 0 ? dp[i-2] + abs(h[i-2]-h[i]) : INF;
    dp[i] = min(h1,h2);
  }
  cout << dp[n-1] << endl;
}