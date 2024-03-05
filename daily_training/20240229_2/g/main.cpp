#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int l,q; cin >> l >> q;
  set<int> st = {0,l};
  REP(i,q) {
    int c,x; cin >> c >> x;
    if (c == 1) {
      st.insert(x);
    } else {
      auto it = st.lower_bound(x);
      int right = *it;
      int left = *(--it);
      cout << right - left << endl;
    }
  }

  return 0;
}