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
  x[0] = 0; x[n+1] = w;

  vector<mint> dp(n+2), sum(n+2);
  dp[0] = 1; sum[0] = 1;
  for(int i = 1; i <= n+1; i++) {
    int posL = lower_bound(x.begin(),x.end(),x[i]-r) - x.begin();
    int posR = lower_bound(x.begin(),x.end(),x[i]-l+1) - x.begin();
    posR--;

    if (posR != -1) dp[i] = sum[posR];
    if (posL >= 1) dp[i] -= sum[posL - 1];
    sum[i] = sum[i-1] + dp[i];
  }
  cout << dp[n+1].val() << endl;
  return 0;
}