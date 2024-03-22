#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n,k; cin >> n >> k;
  vector<int> a(k);
  REP(i,k) cin >> a[i];

  // dp[i] := 石が i 個ある状態から始めたときに先手が取ることができる石の個数
  vector<int> dp(n+1);
  REP(i,n+1) REP(j,k) {
    if (i-a[j] < 0) break;
    dp[i] = max(dp[i], a[j] + (i-a[j]) - dp[i-a[j]]);
  }

  cout << dp[n] << endl;
  return 0;
}