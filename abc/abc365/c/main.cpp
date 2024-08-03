#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;
using P = pair<int,int>;
const ll LINF = 1e18;

int main() {
  int n; ll m;
  cin >> n >> m;
  vector<ll> a(n);
  REP(i,n) cin >> a[i];

  ll ok = 0, ng = LINF;
  while(abs(ok-ng) > 1) {
    ll mid = (ok+ng) / 2;
    ll tot = 0;
    REP(i,n) { tot += min(a[i],mid); }
    if (tot <= m) ok = mid;
    else ng = mid;
  }

  if (ok == LINF-1) cout << "infinite" << endl;
  else cout << ok << endl;
  return 0;
}