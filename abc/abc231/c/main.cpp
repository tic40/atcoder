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
  int n,q;
  cin >> n >> q;
  vector<ll> a(n);
  REP(i,n) cin >> a[i];

  sort(a.begin(),a.end());
  REP(i,q) {
    ll x; cin >> x;
    auto it = lower_bound(a.begin(), a.end(), x);
    cout << n - (it - a.begin()) << endl;
  }
  return 0;
}