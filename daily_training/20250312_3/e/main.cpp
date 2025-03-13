#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n; cin >> n;
  vector<int> a(n);
  multiset<int> st;
  REP(i,n) cin >> a[i];
  REP(i,n-1) { int b; cin >> b; st.insert(b); }

  sort(a.rbegin(),a.rend());
  int ans = -1;
  REP(i,n) {
    auto it = st.lower_bound(a[i]);
    if (it == st.end()) {
      if (ans != -1) { ans = -1; break; }
      ans = a[i];
    } else {
      st.erase(it);
    }
  }
  cout << ans << endl;
  return 0;
}
