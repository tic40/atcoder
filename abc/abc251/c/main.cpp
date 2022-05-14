#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)

int main() {
  int n; cin >> n;
  unordered_set<string> st;
  int ans = 1e9+5, mx = -1;

  REP(i,n) {
    string s; int t; cin >> s >> t;
    if (st.count(s)) continue;
    st.insert(s);
    if (mx < t) { mx = t; ans = i+1; }
  }
  cout << ans << endl;
  return 0;
}