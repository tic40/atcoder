#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;
template<class T> void chmax(T& a, T b) { a = max(a,b); }

int main() {
  int n; cin >> n;
  vector g(n,vector<int>(n,0));
  REP(i,n-1) {
    for(int j = i+1; j < n; j++) {
      cin >> g[i][j];
    }
  }

  vector<ll> dp(1<<n);
  REP(i,n-1) for(int j = i+1; j < n; j++) {
    int bit = (1<<i) + (1<<j);
    dp[bit] = g[i][j];
  }

  for(int bit = 0; bit < (1<<n); bit++) {
    for(int pbit = bit; pbit > 0; pbit = (pbit-1) & bit) {
      if(dp[pbit] == 0) continue;
      chmax(dp[bit], dp[bit-pbit] + dp[pbit]);
    }
  }
  cout << dp[(1<<n)-1] << endl;
  return 0;
}