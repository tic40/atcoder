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
  ll n,d,p; cin >> n >> d >> p;
  vector<ll> f(n);
  REP(i,n) cin >> f[i];

  sort(f.rbegin(),f.rend());
  vector<ll> s(n+1);
  REP(i,n) s[i+1] = s[i]+f[i];

  ll ans = LINF;
  REP(i,n+1) {
    ll now = i * p;
    ll m = i * d;
    now += s[n] - s[min(n,m)];
    ans = min(ans,now);
    if (m >= n) break;
  }

  cout << ans << endl;
  return 0;
}