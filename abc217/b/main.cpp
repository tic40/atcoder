#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)

int main() {
  set<string> st;
  REP(i,3) {
    string s; cin >> s;
    st.insert(s);
  }

  for(string v: { "ABC", "ARC", "AGC", "AHC" }) {
    if (st.find(v) == st.end()) cout << v << endl;
  }

  return 0;
}