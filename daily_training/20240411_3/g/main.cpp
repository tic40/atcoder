#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;
template<class T> void chmax(T& a, T b) { a = max(a,b); }

int main() {
  int n; cin >> n;
  vector d(n,vector<int>(n));
  REP(i,n-1) for(int j = i+1; j < n; j++) cin >> d[i][j];

  vector<ll> dp(1<<n);
  REP(bit,1<<n) {
    REP(j,n) for(int k = j+1; k < n; k++) {
      if (bit >> j & 1) || (bit >> k & 1) continue;
      int nbit = bit | (1 << j) | (1 << k);
      chmax(dp[nbit],dp[bit] + d[j][k]);
    }
  }
  cout << dp[(1<<n)-1] << endl;
  return 0;
}