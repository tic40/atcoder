#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
using ll = long long;

vector<pair<ll, ll>> prime_factorize(ll n) {
  vector<pair<ll,ll>> res;
  for (ll a = 2; a * a <= n; a++) {
    if (n % a != 0) continue;
    ll ex = 0;
    while (n % a == 0) { ++ex; n /= a; }
    res.push_back({a, ex});
  }
  if (n != 1) res.push_back({n, 1});
  return res;
}

int n,m;
set<int> st;
vector<int> num(100001);

void solve() {
  set<int> pfact;
  for(int v: st) {
    auto pf = prime_factorize(v);
    for(auto v2: pf) pfact.insert( v2.first );
  }
  for(int v: pfact) {
    for(int i = v; i <= m; i+=v) num[i]=1;
  }

  vector<int> ans;
  for(int i = 1; i <= m; i++) {
    if (num[i] == 0) ans.push_back(i);
  }

  cout << ans.size() << endl;
  for(int v: ans) cout << v << endl;
  return;
}

int main() {
  cin >> n >> m;
  REP(i,n) {
    int a; cin >> a;
    st.insert(a);
  }

  solve();
  return 0;
}