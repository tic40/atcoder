#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(int)(n);i++)

int main() {
  int n; cin >> n;
  set<vector<int>> st;
  REP(i,n) {
    int l; cin >> l;
    vector<int> v(l);
    REP(j,l) cin >> v[j];
    st.insert(v);
  }

  cout << st.size() << endl;
  return 0;
}