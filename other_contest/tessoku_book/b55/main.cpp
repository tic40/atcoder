#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int q; cin >> q;
  set<int> st;
  REP(_,q) {
    int t,x; cin >> t >> x;
    if (t == 1) {
      st.insert(x);
    } else {
      if (st.empty()) { cout << -1 << endl; continue; }

      auto it = st.lower_bound(x);
      int ans = 1e9;
      if (it != st.end()) ans = min(ans, abs(x - *it));
      it--;
      if (it != st.end()) ans = min(ans, abs(x - *it));
      cout << ans << endl;
    }
  }
  return 0;
}