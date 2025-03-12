#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;

int main() {
  int n; cin >> n;
  vector<ll> a(n);
  REP(i,n) cin >> a[i];

  vector<ll> s(n+1);
  REP(i,n) s[i+1] = s[i]^a[i];

  ll ans = 0;
  REP(bit,30) {
    int one = 0;
    REP(i,n+1) if (s[i] >> bit & 1) one++;
    ans += (ll)one * (n+1-one) * (1LL << bit);
  }

  REP(i,n) ans -= a[i];
  cout << ans << endl;
  return 0;
}
