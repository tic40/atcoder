#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;

int main() {
  ll n,l,r; cin >> n >> l >> r;
  vector<ll> a(n);
  REP(i,n) cin >> a[i];

  REP(i,n) {
    if (a[i] <= l) {
      cout << l << " ";
    } else if (a[i] >= r) {
      cout << r << " ";
    } else {
      cout << a[i] << " ";
    }
  }
  return 0;
}