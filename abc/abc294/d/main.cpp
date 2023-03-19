#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n,q; cin >> n >> q;
  int now = 1;
  set<int> st;
  REP(_,q) {
    int t; cin >> t;
    if (t == 1) { st.insert(now); now++; }
    if (t == 2) { int x; cin >> x; st.erase(x); }
    if (t == 3) cout << *st.begin() << endl;
  }
  return 0;
}