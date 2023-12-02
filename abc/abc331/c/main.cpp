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
  int n; cin >> n;
  vector<int> a(n);
  REP(i,n) cin >> a[i];
  auto b = a;
  sort(b.begin(),b.end());
  vector<ll> s(n+1);
  REP(i,n) s[i+1] = s[i]+b[i];

  REP(i,n) {
    auto it = upper_bound(b.begin(),b.end(),a[i]);
    int idx = it - b.begin();
    ll ans = s[n] - s[idx];
    cout << ans << " ";
  }
  cout << endl;

  return 0;
}