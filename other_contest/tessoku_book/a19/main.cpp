#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;

int main() {
  int n,W; cin >> n >> W;
  vector<int> w(n),v(n);
  REP(i,n) cin >> w[i] >> v[i];

  vector<ll> dp(W+1,-1);
  dp[0] = 0;
  REP(i,n) {
    vector<ll> p(W+1);
    swap(dp,p);
    REP(j,W+1) {
      dp[j] = p[j];
      if (j-w[i] >= 0 && p[j-w[i]] >= 0) {
        dp[j] = max(dp[j],p[j-w[i]]+v[i]);
      }
    }
  }

  ll ans = *max_element(dp.begin(),dp.end());
  cout << ans << endl;
  return 0;
}