#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  auto in = [&]() {
    int n; cin >> n;
    unordered_set<int> st;
    REP(i,n) { int x; cin >> x; st.insert(x); }
    return st;
  };

  auto sa = in(), sb = in(), sc = in();
  unordered_set<int> st;
  for(auto v1: sa) for(auto v2: sb) for(auto v3: sc) st.insert(v1+v2+v3);

  int q; cin >> q;
  REP(_,q) {
    int x; cin >> x;
    cout << (st.count(x) ? "Yes" : "No") << endl;
  }
  return 0;
}