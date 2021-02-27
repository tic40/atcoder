#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
using ll = long long;
const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;

int k,t;
vector<int> a;

void solve() {
  sort(a.rbegin(),a.rend());
  int mx = a[0];
  int ans = max(0, mx-1-(k-mx));
  cout << ans << endl;
  return;
}

int main() {
  cin >> k >> t;
  a.resize(t);
  REP(i,t) cin >> a[i];

  solve();
  return 0;
}