#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n; cin >> n;
  vector<int> a(n-1),b(n-1);
  REP(i,n-1) { cin >> a[i]; a[i]--; }
  REP(i,n-1) { cin >> b[i]; b[i]--; }

  vector<int> dp(n,-1e9);
  dp[0] = 0;
  REP(i,n-1) {
    dp[a[i]] = max(dp[a[i]], dp[i]+100);
    dp[b[i]] = max(dp[b[i]], dp[i]+150);
  }

  cout << dp[n-1] << endl;
  return 0;
}