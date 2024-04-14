#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;
using P = pair<ll,ll>;

int main() {
  ll l,r; cin >> l >> r;
  vector<P> ans;
  while(l < r) {
    if (l%2) {
      ans.emplace_back(l,l+1);
      l = l+1;
    } else {
      for(ll i = 60; i >= 0; i--) {
        ll p = 1LL<<i;
        if (l % p) continue;
        ll nl = p * (l / p + 1);
        if (nl > r) continue;

        ans.emplace_back(l,nl);
        l = nl;
        break;
      }
    }
  }

  cout << ans.size() << endl;
  for(auto [k,v]: ans) cout << k << " " << v << endl;
  return 0;
}