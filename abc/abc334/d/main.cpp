#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;

int main() {
  ll n,q; cin >> n >> q;
  vector<ll> r(n);
  REP(i,n) cin >> r[i];
  sort(r.begin(),r.end());
  vector<ll> s(n+1);
  REP(i,n) s[i+1] = s[i] + r[i];

  REP(_,q) {
    ll x; cin >> x;
    int idx = upper_bound(s.begin(),s.end(),x) - s.begin();
    cout << max(0,idx-1) << endl;
  }
  return 0;
}