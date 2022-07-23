#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'
using ll = long long;

int main() {
  int n,m; cin >> n >> m;
  vector<int> x(n),b(n+1);
  REP(i,n) cin >> x[i];
  REP(i,m) {
    int c,y; cin >> c >> y;
    b[c] = y;
  }

  vector<ll> dp(n+1,-1);
  dp[0] = 0;
  REP(i,n) {
    vector<ll> p(n+1,-1);
    swap(dp,p);
    REP(cnt,n) {
      dp[0] = max(dp[0], p[cnt]);
      if (p[cnt] != -1) {
        dp[cnt+1] = max(dp[cnt+1], p[cnt]+x[i]+b[cnt+1]);
      }
    }
  }

  ll ans = *max_element(dp.begin(),dp.end());
  cout << ans << endl;
  return 0;
}