#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<(int)(n);i++)
using ll = long long;
const int INF = 1e9;
const ll LINF = 1e18;
const int MOD = 1e9+7;

int main() {
  ll n;
  cin >> n;
  ll ans = 0;
  for(ll i = 1; i <= n;) {
    ll x = n/i; // 今の値
    ll ni = n/x+1; // 次のi
    ans += x*(ni-i); // n/i = x を満たす数はni-i
    cout << "x: " << x << " ni: " << ni << endl;
    i = ni;
  }

  cout << ans << endl;
  return 0;
}