#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'
using ll = long long;
const ll LINF = numeric_limits<ll>::max();

int main() {
  int n,m; cin >> n >> m;
  vector<ll> x(n),y(n),z(n);
  REP(i,n) cin >> x[i] >> y[i] >> z[i];

  ll ans = -LINF;
  REP(bit, 1<<3) {
    vector<ll> sum(n);
    REP(i,n) {
      sum[i] += (bit >> 2 & 1) ? x[i] : -x[i];
      sum[i] += (bit >> 1 & 1) ? y[i] : -y[i];
      sum[i] += (bit & 1) ? z[i] : -z[i];
    }
    sort(sum.rbegin(),sum.rend());
    ans = max(ans, accumulate(sum.begin(), sum.begin()+m, 0LL));
  }

  cout << ans << endl;
  return 0;
}