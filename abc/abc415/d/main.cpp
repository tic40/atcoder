#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;
using P = pair<ll,ll>;

int main() {
  ll n; int m; cin >> n >> m;
  vector<P> pa;
  REP(i,m) {
    ll a,b; cin >> a >> b;
    pa.emplace_back(a-b,a);
  }
  sort(pa.begin(),pa.end());
  ll ans = 0;
  for(auto [d,a]: pa) {
    if (n < a) continue;
    ll x = (n-a)/d + 1;
    ans += x;
    n -= d*x;
  }
  cout << ans << endl;
  return 0;
}