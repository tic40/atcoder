#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'
using ll = long long;

int main() {
  ll a,b; cin >> a >> b;

  auto f = [&](ll g) -> double {
    return (double)a / sqrt(g) + (g-1)*b;
  };

  ll low = 1;
  ll high = a/b;
  while(high - low > 2) {
    ll c1 = (low * 2 + high) / 3;
    ll c2 = (low + high * 2) / 3;
    if (f(c1) > f(c2)) low = c1;
    else high = c2;
  }
  auto ans = f(low);
  for(ll i = low; i <= high; i++) ans = min(ans,f(i));
  printf("%.10f\n", ans);
  return 0;
}