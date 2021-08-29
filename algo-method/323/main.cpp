#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)

int main() {
  int n,m;
  cin >> n >> m;
  vector<int> d(m);
  REP(i,m) cin >> d[i];

  vector<bool> dp(n+1);
  dp[0] = true;
  REP(i,n+1) {
    if (dp[i]) {
      for(int v: d) {
        int ni = i+v;
        if (n < ni) continue;
        dp[ni] = true;
      }
    }
  }

  if (dp[n]) cout << "Yes";
  else cout << "No";
  cout << endl;

  return 0;
}