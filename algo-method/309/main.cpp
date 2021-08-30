#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)

int main() {
  int n,m;
  cin >> n >> m;
  vector<int> a(n);
  REP(i,n) cin >> a[i];

  vector<bool> dp(m+1);
  dp[0]=true;

  REP(i,n) {
    for (int j = m; j >= 0; j--) {
      if(j-a[i] >= 0) dp[j] = dp[j] || dp[j - a[i]];
    }
  }

  cout << (dp[m] ? "Yes" : "No") << endl;
  return 0;
}