#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'

int main() {
  int n; cin >> n;
  unordered_set<string> st;
  REP(i,n) {
    string s; cin >> s;
    if (st.count(s)) continue;
    st.insert(s);
    cout << i+1 << endl;
  }
  return 0;
}