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

vector<pair<ll,ll>> prime_factorize(ll n) {
  vector<pair<ll,ll>> res;
  for(ll a = 2; a*a <= n; a++) {
    if (n%a != 0) continue;
    ll ex = 0;
    while(n%a == 0) { ex++; n /= a; }
    res.emplace_back(a,ex);
  }
  if (n != 1) res.emplace_back(n,1);
  return res;
}

int main() {
  int t; cin >> t;
  REP(_,t) {
    ll n; cin >> n;
    auto pf = prime_factorize(n);
    cout << (pf.size() >= 2 ? "Yes" : "No") << endl;
  }
  return 0;
}