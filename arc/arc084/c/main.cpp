#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
using ll = long long;
const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;

int n;
vector<int> a,b,c;

void solve() {
  sort(a.begin(),a.end());
  sort(b.begin(),b.end());
  sort(c.begin(),c.end());

  ll ans = 0;
  REP(i,n) {
    int mid = b[i];
    // midより大きいidx
    auto idxa = lower_bound(a.begin(),a.end(),mid)-1-a.begin();
    // midより小さいidx
    auto idxc = upper_bound(c.begin(),c.end(),mid)-c.begin();
    ans += (idxa+1)*(n-idxc);
  }
  cout << ans << endl;
  return;
}

int main() {
  cin >> n;
  a.resize(n);
  b.resize(n);
  c.resize(n);
  REP(i,n) cin >> a[i];
  REP(i,n) cin >> b[i];
  REP(i,n) cin >> c[i];

  solve();
  return 0;
}