#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'
using ll = long long;

int main() {
  int n,q;
  cin >> n >> q;
  vector<ll> a(n);
  REP(i,n) cin >> a[i];

  vector<ll> s(n);
  s[0] = a[0] - 1;
  for(int i = 1; i < n; i++) s[i] = s[i-1] + (a[i] - a[i-1] - 1);

  REP(i,q) {
    ll k; cin >> k;
    auto it = lower_bound(s.begin(),s.end(),k);
    if (it == s.end()) {
      cout << a.back() + (k - s.back()) << endl;
    } else {
      int idx = it - s.begin();
      cout << a[idx] - (s[idx] - k + 1) << endl;
    }
  }
  return 0;
}