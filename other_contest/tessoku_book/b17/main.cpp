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
    if (i-1 >= 0) dp[i] = min(dp[i],dp[i-1] + abs(h[i]-h[i-1]));
    if (i-2 >= 0) dp[i] = min(dp[i],dp[i-2] + abs(h[i]-h[i-2]));
  }

  vector<int> ans = { n-1 };
  int i = n-1;
  while(i > 0) {
    int d = dp[i]-dp[i-1];
    if (d == abs(h[i]-h[i-1])) i--;
    else i-=2;
    ans.push_back(i);
  }

  reverse(ans.begin(),ans.end());
  cout << ans.size() << endl;
  for(int v: ans) cout << v+1 << " ";
  return 0;
}