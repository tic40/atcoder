#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<(int)(n);i++)
using ll = long long;

int main() {
  int q; cin >> q;

  map<ll,int> mp;
  set<ll> st; // keyを持たせる
  st.insert(-1); // -1は番兵

  REP(i,q) {
    int t; cin >> t;
    ll x; cin >> x;
    int k; if (t == 2 || t == 3) cin >> k;

    if (t == 1) {
      mp[x]++;
      st.insert(x);
    }

    if (t == 2) {
      ll res = -1;
      for(auto it = --st.upper_bound(x); it != st.begin(); it--) {
        k -= mp[*it];
        if (k <= 0) { res = *it; break; }
      }

      cout << res << endl;
    }

    if (t == 3) {
      ll res = -1;
      for(auto it = st.lower_bound(x); it != st.end(); it++) {
        k -= mp[*it];
        if (k <= 0) { res = *it; break; }
      }

      cout << res << endl;
    }
  }
  return 0;
}