#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n,s; cin >> n >> s;
  vector<int> a(n);
  REP(i,n) cin >> a[i];

  vector<bool> dp(1e4+1);
  dp[0] = true;
  REP(i,n) {
    vector<bool> p(1e4+1);
    swap(dp,p);
    REP(j,s+1) {
      dp[j] = p[j];
      if (j-a[i] >= 0) dp[j] = dp[j] || p[j-a[i]];
    }
  }

  cout << (dp[s] ? "Yes" : "No") << endl;
  return 0;
}