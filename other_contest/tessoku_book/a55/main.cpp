#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int q; cin >> q;
  multiset<int> st;
  REP(_,q) {
    int t,x; cin >> t >> x;
    if (t == 1) {
      st.insert(x);
    } else if (t == 2) {
      st.erase(x);
    } else {
      auto it = st.lower_bound(x);
      if (it == st.end()) cout << -1 << endl;
      else cout << *it << endl;
    }
  }
  return 0;
}