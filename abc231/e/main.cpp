#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<(int)(n);i++)
using ll = long long;
const int INF = 1e9;
const ll LINF = 1e18;

ll n,x;
vector<ll> a;

void solve() {
  vector<ll> dp(2,LINF);
  dp[0] = 0;

  REP(i,n-1) {
    // 次の硬貨の倍率(A[i+1] は A[i]の倍数になっている)
    ll d = a[i+1]/a[i];
    ll r = x%d;
    vector<ll> p(2,LINF);
    // pからdpへの遷移
    swap(dp,p);
    // 今の桁の繰り下がり、次の桁の繰り下がり
    REP(c,2) REP(nc,2) {
      // a[i] - c + nc*d - b[i] = x[i]
      // a[i]-b[i] = x[i]+c-nc*d
      ll nr = r+c-nc*d;
      dp[nc] = min(dp[nc], p[c]+abs(nr));
    }
    x /= d;
  }

  ll ans = LINF;
  REP(c,2) ans = min(ans, dp[c]+abs(x+c));
  cout << ans << endl;
  return;
}

int main() {
  cin >> n >> x;
  a.resize(n);
  REP(i,n) cin >> a[i];

  solve();
  return 0;
}