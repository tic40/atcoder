#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = unsigned long long;
using P = pair<int,int>;
const int INF = numeric_limits<int>::max();
const ll LINF = numeric_limits<ll>::max();
const int MOD = 1e9+7;
// using mint = modint998244353; // modint1000000007;

int main() {
  ll n; cin >> n;

  ll ans = 0, pow2 = 2;
  REP(_,62) {
    if (pow2 > n) break;
    ll x = n/pow2;
    if (x == 0) break;
    ll l = sqrtl(x);
    ans += (l+1)/2;
    if (pow2 > n/2) break;
    pow2*=2;
  }
  cout << ans << endl;
  return 0;
}
