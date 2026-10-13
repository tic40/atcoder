#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;

int main() {
  int n,k; ll x;
  cin >> n >> k >> x;
  vector<ll> a(n);
  REP(i,n) cin >> a[i];
  sort(a.rbegin(),a.rend());
  ll tot = 0;
  REP(i,k) {
    tot += a[n-k+i];
    if (x <= tot) { cout << n-k+(i+1) << endl; return 0; }
  }
  cout << -1 << endl;
  return 0;
}
