#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'
using ll = long long;
const ll LINF = numeric_limits<ll>::max();

int main() {
  ll n,m; cin >> n >> m;
  vector<ll> a(n);
  REP(i,n) cin >> a[i];

  vector<ll> dp(m+1, -LINF);
  dp[0] = 0;
  REP(i,n) {
    vector<ll> p(m+1, -LINF);
    p[0] = 0;
    swap(dp,p);

    REP(j,m) {
      if (p[j] == -LINF) continue;
      dp[j+1] = max(p[j+1], p[j] + a[i] * (j+1));
    }
  }

  cout << dp[m] << endl;
  return 0;
}