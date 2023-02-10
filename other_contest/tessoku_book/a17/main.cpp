#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n; cin >> n;
  vector<int> a(n-1),b(n-2);
  REP(i,n-1) cin >> a[i];
  REP(i,n-2) cin >> b[i];

  vector<int> dp(n,1e9);
  dp[0] = 0;
  REP(i,n) {
    if (i-1 >= 0) dp[i] = min(dp[i], dp[i-1]+a[i-1]);
    if (i-2 >= 0) dp[i] = min(dp[i], dp[i-2]+b[i-2]);
  }

  int i = n-1;
  vector<int> ans = { n-1 };
  while(i > 0) {
    int now = dp[i];
    if (a[i-1] == now - dp[i-1]) i--;
    else i-=2;
    ans.push_back(i);
  }

  reverse(ans.begin(),ans.end());
  cout << ans.size() << endl;
  for(int v: ans) cout << v+1 << " ";
  return 0;
}