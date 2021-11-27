#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<(int)(n);i++)
using ll = long long;

int main() {
  ll n,w;
  cin >> n >> w;
  vector<pair<ll, ll>> pa(n);
  REP(i,n) cin >> pa[i].first >> pa[i].second;
  sort(pa.rbegin(), pa.rend());

  ll cur = 0, ans = 0;
  for(auto [a,b]: pa) {
    if (cur + b <= w) {
      cur += b;
      ans += a*b;
    } else {
      ans += a*(w-cur);
      break;
    }
  }

  cout << ans << endl;
  return 0;
}