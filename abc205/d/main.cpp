#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
using ll = long long;
const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;

ll n,q;
vector<ll> a,k,sum;

void calc(ll x) {
  auto it = lower_bound(sum.begin(), sum.end(), x);
  int idx = it-sum.begin();

  if (idx == n) {
    cout << a[n-1] + (x - sum[n-1]) << endl;
  } else {
    cout << a[idx] - (sum[idx] - x + 1) << endl;
  }
  return;
}

void solve() {
  sum.resize(n);
  REP(i,n) sum[i] += a[i] - (i+1);

  REP(i,q) calc(k[i]);
  return;
}

int main() {
  cin >> n >> q;
  a.resize(n);
  k.resize(q);
  REP(i,n) cin >> a[i];
  REP(i,q) cin >> k[i];

  solve();
  return 0;
}