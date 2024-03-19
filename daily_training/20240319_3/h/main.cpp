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
  int n,k; cin >> n >> k;
  vector<int> a(n);
  REP(i,n) cin >> a[i];
  set<ll> st;
  auto push = [&](ll x) {
    REP(i,n) st.insert(x+a[i]);
  };
  push(0);

  REP(i,k-1) {
    ll x = *st.begin();
    st.erase(x);
    push(x);
  }
  ll ans = *st.begin();
  cout << ans << endl;
  return 0;
}