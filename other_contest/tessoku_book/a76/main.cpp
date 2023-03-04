#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using mint = modint1000000007;

int main() {
  int n,w,l,r; cin >> n >> w >> l >> r;
  vector<int> x(n+2);
  for(int i = 1; i <= n; i++) cin >> x[i];
  x[n+1] = w;

  vector<mint> dp(n+2), s(n+2);
  dp[0] = 1; s[0] = 1;
  for(int i = 1; i < n+2; i++) {
    int nl = lower_bound(x.begin(),x.end(),x[i]-r) - x.begin();
    int nr = upper_bound(x.begin(),x.end(),x[i]-l) - x.begin() - 1;

    if (nl > 0 && nl <= nr) dp[i] = s[nr] - s[nl-1];
    s[i] = s[i-1] + dp[i];
  }
  cout << dp[n+1].val() << endl;
  return 0;
}