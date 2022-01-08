#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(int)(n);i++)
#define ALL(x) x.begin(), x.end()
using ll = long long;
const ll LINF = 1e18;

ll n,k;
vector<ll> a,b,c;

void solve() {

  ll ok = LINF, ng = 0;
  while(abs(ok - ng) > 1) {
    ll mid = (ok+ng)/2;

    // mid以下に何個数字があるか
    ll cnt = 0;
    REP(i,n) {
      if (mid < b[i]) continue;
      cnt += min(a[i], (mid-b[i]) / c[i] + 1);
    }

    if (k <= cnt) ok = mid;
    else ng = mid;
  }

  cout << ok << endl;
  return;
}

int main() {
  cin >> n >> k;

  a.resize(n);
  b.resize(n);
  c.resize(n);
  REP(i,n) cin >> a[i] >> b[i] >> c[i];

  solve();
  return 0;
}