#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;

int main() {
  ll n,x; cin >> n >> x;
  vector<ll> a(n);
  REP(i,n) cin >> a[i];
  sort(a.begin(),a.end());

  bool ok = false;
  REP(i,n) {
    auto it = lower_bound(a.begin(),a.end(),a[i]-x);
    if (a[i] - *it == x) ok = true;
  }
  cout << (ok ? "Yes" : "No") << endl;
  return 0;
}