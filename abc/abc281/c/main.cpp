#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;

int main() {
  ll n,t; cin >> n >> t;
  vector<ll> a(n);
  REP(i,n) cin >> a[i];
  ll tot = accumulate(a.begin(),a.end(),0LL);

  ll r = t / tot; // 何周するか
  t -= tot * r;

  REP(i,n) {
    t -= a[i];
    if (t <= 0) {
      cout << i+1 << " " << a[i]+t << endl;
      return 0;
    }
  }

  return 0;
}