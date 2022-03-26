#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)

int main() {
  int n; cin >> n;
  set<int> st;
  REP(i,n) {
    int a; cin >> a;
    st.insert(a);
  }

  int i = 0;
  while(1) {
    if (st.count(i)) { i++; continue; }
    cout << i << endl; break;
  }
  return 0;
}
