#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;
using P = pair<int,int>;
const int INF = numeric_limits<int>::max();
const ll LINF = numeric_limits<ll>::max();
const int MOD = 1e9+7;
// using mint = modint998244353; // modint1000000007;

int main() {
  ll n; cin >> n;
  ll ans = n/3 + n/5 + n/7;
  ans -= n/(3*5) + n/(5*7) + n/(3*7);
  ans += n/(3*5*7);
  cout << ans << endl;
  return 0;
}