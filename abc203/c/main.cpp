#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
using ll = long long;
const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;

ll n,k;
vector<pair<ll, ll>> pa;

void solve() {
  sort(pa.begin(), pa.end());
  REP(i,n) {
    if (k < pa[i].first) break;
    k+=pa[i].second;
  }

  cout << k << endl;
  return;
}

int main() {
  cin >> n >> k;
  REP(i,n) {
    ll a,b; cin >> a >> b;
    pa.push_back({a, b});
  }

  solve();
  return 0;
}