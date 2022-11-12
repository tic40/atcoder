#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'

const vector<vector<char>> c = {
  {'H', 'D', 'C', 'S'},
  {'A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K'}
};

int main() {
  int n; cin >> n;
  vector<string> s(n);
  REP(i,n) cin >> s[i];
  set<string> st;
  REP(i,n) st.insert(s[i]);
  if ((int)st.size() != n) { cout << "No" << endl; return 0; }

  REP(i,2) REP(j,n) {
    bool ok = false;
    for(auto v: c[i]) if (s[j][i] == v) ok = true;
    if (!ok) { cout << "No" << endl; return 0; }
  }

  cout << "Yes" << endl;
  return 0;
}