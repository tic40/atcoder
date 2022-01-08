#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
typedef long long ll;

int main() {
  int n;
  ll ans = 0;
  cin >> n;
  vector<ll> a(n+1), b(n);
  REP(i, n+1) cin >> a[i];
  REP(i, n) cin >> b[i];

  REP(i, n) {
    ll m;
    m = min(b[i], a[i]);
    a[i]-=m;
    b[i]-=m;
    ans+=m;

    if (b[i] > 0) {
      m = min(b[i], a[i+1]);
      a[i+1]-=m;
      ans+=m;
    }
  }
  cout << ans << endl;
}