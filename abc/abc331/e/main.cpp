#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;
using P = pair<int,int>;

int main() {
  int n,m,l;
  cin >> n >> m >> l;
  vector<int> a(n),b(m);
  REP(i,n) cin >> a[i];
  REP(i,m) cin >> b[i];

  vector<P> bp(m);
  REP(i,m) bp[i] = { b[i], i };
  sort(bp.rbegin(),bp.rend());
  set<P> st;
  REP(i,l) {
    int c,d; cin >> c >> d;
    c--; d--;
    st.insert(P{c,d});
  }

  ll ans = 0;
  REP(i,n) {
    for(auto [v,k]: bp) {
      if (st.find(P{i,k}) != st.end()) continue;
      ans = max(ans,(ll)a[i]+v);
      break;
    }
  }
  cout << ans << endl;
  return 0;
}