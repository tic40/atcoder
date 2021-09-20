#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
using ll = long long;
const int MOD = 1e9+7;

int main() {
  ll n,q;
  cin >> n >> q;
  vector<ll> x(q),y(q),z(q),w(q);
  REP(i,q) {
    cin >> x[i] >> y[i] >> z[i] >> w[i];
    x[i]--, y[i]--, z[i]--;
  }

  ll ans = 1;
  REP(i,60) {
    ll cnt = 0;
    REP(bit, 1<<n) {
      vector<ll> arrb(n);
      REP(k,n) arrb[k] = bit >> k & 1;

      bool ok = true;
      REP(k,q) {
        if ( (arrb[x[k]] | arrb[y[k]] | arrb[z[k]]) != (w[k] >> i & 1)) {
          ok = false;
          break;
        }
      }

      if (ok) cnt++;
    }
    ans *= cnt;
    ans %= MOD;
  }

  cout << ans << endl;
  return 0;
}