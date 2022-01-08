#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
using ll = long long;

int main() {
  int n,m;
  cin >> n >> m;
  ll x[n],y[n],z[n];
  REP(i,n) cin >> x[i] >> y[i] >> z[i];

  ll sum[1<<3][n],ans = 0;
  for (int bit = 0; bit < (1<<3); bit++) {
    REP(i,n) {
      sum[bit][i] = 0;
      sum[bit][i] += (bit >> 0 & 1) ? x[i] : -x[i];
      sum[bit][i] += (bit >> 1 & 1) ? y[i] : -y[i];
      sum[bit][i] += (bit >> 2 & 1) ? z[i] : -z[i];
    }
    sort(sum[bit], sum[bit]+n, greater<ll>());
    ll tmp = 0;
    REP(i,m) tmp += sum[bit][i];
    if (ans < tmp) ans = tmp;
  }

  cout << ans << endl;
  return 0;
}