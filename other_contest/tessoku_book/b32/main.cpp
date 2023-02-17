#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n,k; cin >> n >> k;
  vector<int> a(k);
  REP(i,k) cin >> a[i];

  vector<bool> dp(n+1);
  REP(i,n+1) REP(j,k) {
    int nj = i-a[j];
    if (nj >= 0 && !dp[nj]) { dp[i] = true; break; }
  }

  cout << (dp[n] ? "First" : "Second") << endl;
  return 0;
}