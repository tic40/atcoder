#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  string s,t; cin >> s >> t;
  set<char> st;
  for(auto c: t) st.insert(c);

  bool ok = true;
  REP(i,(int)s.size()-1) {
    if (isupper(s[i+1])) {
      if (st.find(s[i]) == st.end()) ok = false;
    }
  }
  cout << (ok ? "Yes" : "No") << endl;
  return 0;
}