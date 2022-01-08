#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
using ll = long long;
const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;

int n;
vector<ll> a;

void solve() {
  ll offset = 0;
  REP(i,n) offset = a[i]*2 - offset;

  vector<int> ans(n);
  ans[0] = offset / 2;
  REP(i,n-1) ans[i+1] = a[i]*2 - ans[i];

  REP(i,n) cout << ans[i] << " ";
  return;
}

int main() {
  cin >> n;
  a.resize(n);
  REP(i,n) cin >> a[i];

  solve();
  return 0;
}