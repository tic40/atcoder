#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;
using P = pair<ll,ll>;

int main() {
  int n,m; cin >> n >> m;
  vector<ll> p(n),l(m),d(m);
  REP(i,n) cin >> p[i];
  REP(i,m) cin >> l[i];
  REP(i,m) cin >> d[i];

  vector<P> pa(m);
  REP(i,m) pa[i] = {d[i],l[i]};
  sort(pa.rbegin(),pa.rend());
  multiset<ll> st;
  REP(i,n) st.insert(p[i]);

  ll ans = accumulate(p.begin(),p.end(),0LL);
  REP(i,m) {
    auto [nd,nl] = pa[i];
    auto it = st.lower_bound(nl);
    if (it == st.end()) continue;
    ans -= nd;
    st.erase(it);
  }

  cout << ans << endl;
  return 0;
}