#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
template<class T> void chmin(T& a, T b) { a = min(a,b); }

int main() {
  int n; cin >> n;
  vector<int> h(n);
  REP(i,n) cin >> h[i];

  vector<int> dp(n+2, 1e9);
  dp[0] = 0;
  REP(i,n) {
    chmin(dp[i+1], dp[i] + abs(h[i+1]-h[i]));
    chmin(dp[i+2], dp[i] + abs(h[i+2]-h[i]));
  }

  cout << dp[n-1] << endl;
  return 0;
}