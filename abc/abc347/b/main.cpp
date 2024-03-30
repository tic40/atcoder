#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  string s; cin >> s;
  int n = s.size();
  unordered_set<string> st;
  REP(i,n) for(int j = 1; i+j <= n; j++) {
    string t = s.substr(i,j);
    st.insert(t);
  }
  cout << st.size() << endl;
  return 0;
}