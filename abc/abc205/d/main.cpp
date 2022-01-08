#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
using ll = long long;

int n,q;
vector<ll> a,k;

void solve() {
  vector<ll> s(n);
  REP(i,n) {
    if (i == 0) s[i] = a[i]-1;
    else s[i] = s[i-1] + a[i]-a[i-1]-1;
  }

  REP(i,q) {
    auto it = lower_bound(s.begin(), s.end(), k[i]);
    int idx = it-s.begin();
    if (idx == n) {
      cout << a[n-1] + (k[i] - s[n-1]) << endl;
    } else {
      cout << a[idx] - (s[idx] - k[i] + 1) << endl;
    }
  }
  return;
}

int main() {
  cin >> n >> q;
  a.resize(n);
  k.resize(q);
  REP(i,n) cin >> a[i];
  REP(i,q) cin >> k[i];

  solve();
  return 0;
}