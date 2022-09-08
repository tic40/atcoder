#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'
using ll = long long;
const ll INF = 1e18;

int main() {
  int n; cin >> n;

  ll s = 0, l = -INF, h = INF;
  REP(i,n) {
    ll a; int t;
    cin >> a >> t;

    if (t == 1) {
      s += a;
      l += a;
      h += a;
    } else if (t == 2) {
      l = max(l,a);
      h = max(h,a);
    } else {
      l = min(l,a);
      h = min(h,a);
    }
  }

  int q; cin >> q;
  REP(i,q) {
    ll x; cin >> x;
    x += s;
    x = max(x,l);
    x = min(x,h);
    cout << x << endl;
  }
  return 0;
}