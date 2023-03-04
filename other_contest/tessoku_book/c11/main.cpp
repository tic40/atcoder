#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;

int main() {
  int n,k; cin >> n >> k;
  vector<int> a(n);
  REP(i,n) cin >> a[i];

  double ok = 1, ng = 1000000000;
  while(ng - ok > 1.0/1e6) {
    double mid = (ok+ng) / 2;
    ll now = 0;
    REP(i,n) now += (ll)(a[i] / mid);
    if (now >= k) ok = mid;
    else ng = mid;
  }

  REP(i,n) cout << (ll)(a[i]/ok) << " ";
  return 0;
}