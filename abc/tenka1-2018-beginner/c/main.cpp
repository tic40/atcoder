#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
using ll = long long;
const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;

int n;
vector<int> a;

void solve() {
  sort(a.rbegin(),a.rend());

  ll res = 0;
  if (n%2 == 0) {
    REP(i,n/2-1) res+=a[i]*2;
    res += a[n/2-1];
    res -= a[n/2];
    for(int i = n/2+1; i<n; i++) res -= a[i]*2;
  } else {
    REP(i,n/2-1) res += a[i]*2;
    res += a[n/2-1]+a[n/2];
    for(int i = n/2+1; i<n; i++) res -= a[i]*2;

    ll res2 = 0;
    REP(i,n/2) res2+=a[i]*2;
    res2 -= a[n/2]+a[n/2+1];
    for(int i = n/2+2; i<n; i++) res2 -= a[i]*2;
    res = max(res,res2);
  }

  cout << res << endl;
  return;
}

int main() {
  cin >> n;
  a.resize(n);
  REP(i,n) cin >> a[i];

  solve();
  return 0;
}