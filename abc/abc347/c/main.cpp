#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;
const ll LINF = numeric_limits<ll>::max();

int main() {
  ll n,a,b; cin >> n >> a >> b;
  vector<ll> d(n);
  REP(i,n) cin >> d[i];

  ll r = a+b;
  // d[0] を 1 としたとき
  vector<ll> diff(n);
  REP(i,n) {
    diff[i] = d[i] - d[0];
    diff[i] %= r;
  }

  ll mx = LINF;
  REP(i,n) {
    if (diff[i] < a) continue;
    mx = min(mx,diff[i]);
  }
  if (mx == LINF) { cout << "Yes" << endl; return 0; }

  ll nd = r - mx;
  REP(i,n) {
    diff[i] += nd;
    diff[i] %= r;
  }

  bool ok = true;
  REP(i,n) { if (diff[i] >= a) ok = false; }
  cout << (ok ? "Yes" : "No") << endl;
  return 0;
}