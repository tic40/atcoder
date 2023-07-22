#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n; string s; cin >> n >> s;
  set<char> st;
  REP(i,n) {
    st.insert(s[i]);
    if (st.size() == 3) { cout << i+1 << endl; return 0; }
  }
  return 0;
}