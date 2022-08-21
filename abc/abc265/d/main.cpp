#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'
using ll = long long;

int main() {
  int n;
  ll p,q,r;
  cin >> n >> p >> q >> r;
  vector<int> a(n);
  REP(i,n) cin >> a[i];

  vector<ll> m(n+1); // 累積和
  REP(i,n) m[i+1] = m[i]+a[i];

  bool ok = false;
  REP(x,n) {
    auto itx = lower_bound(m.begin()+x, m.end(), p+m[x]);
    if (*itx - m[x] != p) continue;
    int y = itx - m.begin();

    auto ity = lower_bound(m.begin()+y, m.end(), q+m[y]);
    if (*ity - m[y] != q) continue;
    int z = ity - m.begin();

    auto itz = lower_bound(m.begin()+z, m.end(), r+m[z]);
    if (*itz - m[z] != r) continue;

    ok = true;
  }

  cout << (ok ? "Yes" : "No") << endl;
  return 0;
}