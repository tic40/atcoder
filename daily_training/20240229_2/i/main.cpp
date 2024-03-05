#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;
const ll LINF = numeric_limits<ll>::max();

int main() {
  int n; cin >> n;
  vector<int> x(n),y(n);
  REP(i,n) cin >> x[i] >> y[i];

  auto f = [&](int i, int j, int k) {
    i %= n; j %= n; k %= n;
    ll x1 = x[j]-x[i], y1 = y[j]-y[i];
    ll x2 = x[k]-x[i], y2 = y[k]-y[i];
    return abs(x1*y2 - x2*y1)*4;
  };

  // 全体の面積
  ll tot = 0;
  for(int j = 2; j < n; j++) tot += f(0,j-1,j);
  tot /= 4;

  ll s = 0, ans = LINF;
  int j = 1;
  REP(i,n) {
    while(s < tot) {
      s += f(i,j,j+1);
      ans = min(ans,abs(tot-s));
      j++;
    }
    s -= f(i,i+1,j);
    ans = min(ans,abs(tot-s));
  }
  cout << ans << endl;
  return 0;
}