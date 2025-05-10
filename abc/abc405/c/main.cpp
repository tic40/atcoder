#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;

int main() {
  int n; cin >> n;
  vector<int> a(n);
  REP(i,n) cin >> a[i];

  vector<ll> s(n+1);
  REP(i,n) s[i+1] = s[i]+a[i];

  ll ans = 0;
  REP(i,n) ans += (ll)a[i] * (s[n] - s[i+1]);
  cout << ans << endl;
  return 0;
}