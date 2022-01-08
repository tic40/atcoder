#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
using ll = long long;

int n,k;
vector<ll> a,b;

void solve() {
  vector<ll> vec;
  REP(i,n) {
    vec.push_back(b[i]);
    vec.push_back(a[i]-b[i]);
  }

  ll ans = 0;
  sort(vec.rbegin(), vec.rend());

  REP(i,k) ans += vec[i];
  cout << ans << endl;
  return;
}

int main() {
  cin >> n >> k;
  a.resize(n);
  b.resize(n);
  REP(i,n) cin >> a[i] >> b[i];

  solve();
  return 0;
}