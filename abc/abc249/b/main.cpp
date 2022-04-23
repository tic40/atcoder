#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)

int main() {
  string s; cin >> s;
  int n = s.size();
  bool l = false, u = false;
  set<char> st;
  for(char c: s) {
    if ('a' <= c && c <= 'z') l = true;
    if ('A' <= c && c <= 'Z') u = true;
    st.insert(c);
  }

  bool ok = l && u && (int)st.size() == n;
  cout << (ok ? "Yes" : "No") << endl;

  return 0;
}