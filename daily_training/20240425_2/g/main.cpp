#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;

int main() {
  int n,q; cin >> n >> q;
  vector<int> a(n);
  REP(i,n) cin >> a[i];

  sort(a.begin(),a.end());
  vector<ll> s(n+1);
  REP(i,n) s[i+1] = s[i] + a[i];

  REP(i,q) {
    int x; cin >> x;
    int idx = lower_bound(a.begin(),a.end(),x) - a.begin();
    ll left = ll(x) * idx - (s[idx] - s[0]);
    ll right = (s[n] - s[idx]) - ll(x) * (n-idx);
    ll ans = left + right;
    cout << ans << endl;
  }
  return 0;
}