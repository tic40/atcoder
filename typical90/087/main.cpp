#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
using ll = long long;

ll n,p,k;
ll a[45][45], dp[45][45];

ll count(ll x) {
  // init dp
  REP(i,n) REP(j,n) {
    dp[i][j] = (a[i][j] == -1) ? x : a[i][j];
  }

  // warshall floyd
  REP(k,n) REP(i,n) REP(j,n) {
    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
  }

  ll cnt = 0;
  REP(i,n) for(int j = i+1; j < n; j++) {
    if (dp[i][j] <= p) cnt++;
  }

  return cnt;
}

ll binary_search(int key) {
  ll left = 1, right = 1e10;
  REP(i,40) {
    ll mid = (left+right)/2;
    ll res = count(mid);

    if (res <= key) right = min((ll)1e10, mid);
    else left = mid;
  }

  return right;
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