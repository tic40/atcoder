#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)

int main() {
  int n; cin >> n;
  set<string> st;
  pair<int,int> ans;
  REP(i,n) {
    string s; int t;
    cin >> s >> t;
    if (st.count(s)) continue;
    st.insert(s);
    if (ans.first < t) ans = {t,i+1};
  }

  cout << ans.second << endl;
  return 0;
}
