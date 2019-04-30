#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
typedef long long ll;

int main() {
  ll n, a, b, ans = 0;
  cin >> n >> a >> b;
  if (b == 0) {
    cout << n - (n / a) << "\n";
    return 0;
  }
  vector<ll> d(b);
  REP(i, b) cin >> d[i];
  sort(d.begin(), d.end());
  if (d.back() != n) d.push_back(n + 1);
  REP(i, d.size()) {
    ll diff = (i == 0) ? d[i] - 1 : d[i] - d[i - 1] - 1;
    ans += diff - diff / a;
  }
  cout << ans << "\n";
}