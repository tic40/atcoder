#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n; cin >> n;
  vector<string> s(n);
  REP(i,n) cin >> s[i];
  auto t = s;
  REP(i,n) reverse(t[i].begin(),t[i].end());

  int ans = 0;
  unordered_set<string> st;
  REP(i,n) {
    bool find = st.count(s[i]) || st.count(t[i]);
    if (find) continue;
    ans++;
    st.insert(s[i]);
    st.insert(t[i]);
  }
  cout << ans << endl;
  return 0;
}