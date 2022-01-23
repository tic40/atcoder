#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<(int)(n);i++)

int main() {
  int n,m;
  cin >> n >> m;
  vector<string> s(n);
  set<string> st;

  REP(i,n) cin >> s[i];
  REP(i,m) {
    string t; cin >> t;
    st.insert(t);
  }
  REP(i,n) cout << (st.count(s[i]) ? "Yes" : "No") << endl;
  return 0;
}