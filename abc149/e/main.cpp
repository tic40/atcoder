#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
typedef long long ll;

ll n, m, sum,a[100000],k = 2;
int next_combination(int sub) {
  int x = sub & -sub, y = sub + x;
  return (((sub & ~y) / x) >> 1) | y;
}

int main() {
  cin >> n >> m;
  REP(i, n) { cin >> a[i]; }

  int bit = (1<<k)-1;
  vector<ll> p;
  for (;bit < (1<<n); bit = next_combination(bit)) {
    vector<ll> S;

    for (ll i = 0; i < n; ++i) {
      if (bit & (1<<i)) { S.push_back(i); }
    }
    ll sum = 0;
    for (ll i = 0; i < (ll)S.size(); ++i) {
      cout << S[i] << " ";
      sum += a[S[i]];
    }
    p.push_back(sum);
    cout << endl;
  }
  REP(i, n) { p.push_back(a[i]*2); }
  sort (p.begin(), p.end(), greater<ll>());
  ll ans = 0;
  REP(i, m) {
    ans += p[i];
    cout << p[i] << endl;
  }
  cout << ans << endl;
}