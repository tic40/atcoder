#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n,k; cin >> n >> k;
  vector<int> a(n);
  REP(i,n) cin >> a[i];

  // dp[k] := 山が k のとき先手が勝つか
  vector<int> dp(k+1);
  REP(i,k+1) REP(j,n) if (i - a[j] >= 0) {
    dp[i] |= dp[i - a[j]] ^ 1;
  }

  cout << (dp[k] ? "First" : "Second") << endl;
  return 0;
}