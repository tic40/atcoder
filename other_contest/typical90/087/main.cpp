#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define REP(i,n) for(int i=0;i<n;i++)
using ll = long long;

int n,p,k;
vector a(40,vector<int>(40));
vector dp(40,vector<ll>(40));

int count(ll x) {
  REP(i,n) REP(j,n) dp[i][j] = (a[i][j] == -1) ? x : a[i][j];
  // warshall floyd
  REP(k,n) REP(i,n) REP(j,n) {
    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
  }
  int cnt = 0;
  REP(i,n) for(int j = i+1; j < n; j++) if (dp[i][j] <= p) cnt++;
  return cnt;
}

ll binary_search(int key) {
  ll l = 1, r = 1e10;
  REP(i,40) {
    ll mid = (l+r)/2;
    ll res = count(mid);

    if (res <= key) r = mid;
    else l = mid;
  }

  return r;
}

int main() {
  cin >> n >> p >> k;
  REP(i,n) REP(j,n) cin >> a[i][j];
  ll l = binary_search(k);
  ll r = binary_search(k-1);

  ll ans = r-l;
  if (ans >= 1e9) cout << "Infinity" << endl;
  else cout << ans << endl;

  return 0;
}