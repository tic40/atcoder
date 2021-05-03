#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
using ll = long long;
const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;

int n;
vector<int> a,b;

void solve() {
  sort(a.begin(),a.end());
  sort(b.begin(),b.end());
  ll ans = 0;
  REP(i,n) ans += abs(a[i]-b[i]);

  cout << ans << endl;
  return;
}

int main() {
  cin >> n;
  a.resize(n);
  b.resize(n);
  REP(i,n) cin >> a[i];
  REP(i,n) cin >> b[i];
  solve();
  return 0;
}