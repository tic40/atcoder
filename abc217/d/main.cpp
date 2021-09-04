#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)

int l,q;
vector<int> c,x;

void solve() {
  set<int> st;
  // 下限と上限を入れて置く
  st.insert({0, l});

  REP(i,q) {
    if (c[i] == 1) {
      st.insert(x[i]);
    } else {
      auto it = st.lower_bound(x[i]);
      int r = *it;
      int l = *(--it);
      cout << r-l << endl;
    }
  }

  return;
}

int main() {
  cin >> l >> q;
  c.resize(q);
  x.resize(q);
  REP(i,q) cin >> c[i] >> x[i];

  solve();
  return 0;
}