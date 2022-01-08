#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
using ll = long long;
const ll MOD = 998244353;

int n;
vector<int> a;

ll dp[100005][10]; // [i項目目][左端の値k 0-9] = 何通りかの値

void solve() {
  // 1回目の操作をしておく
  dp[1][ (a[0]+a[1]) % 10 ] += 1; // F
  dp[1][ (a[0]*a[1]) % 10 ] += 1; // G

  for(int i = 2; i < n; i++) REP(j,10) {
    if (dp[i-1][j] == 0) continue;

    // 操作F
    dp[i][ (j+a[i]) % 10 ] += dp[i-1][j];
    dp[i][ (j+a[i]) % 10 ] %= MOD;

    // 操作G
    dp[i][ (j*a[i]) % 10 ] += dp[i-1][j];
    dp[i][ (j*a[i]) % 10 ] %= MOD;
  }

  REP(i,10) cout << dp[n-1][i] << endl;
  return;
}

int main() {
  cin >> n;
  a.resize(n);
  REP(i,n) cin >> a[i];

  solve();
  return 0;
}