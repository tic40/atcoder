#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n; cin >> n;
  vector<int> a(n);
  REP(i,n) cin >> a[i];

  auto f = [&]() {
    unordered_set<int> st;
    vector<int> res(n);
    REP(i,n) {
      st.insert(a[i]);
      res[i] = st.size();
    }
    return res;
  };

  auto l = f();
  reverse(a.begin(),a.end());
  auto r = f();
  reverse(r.begin(),r.end());

  int ans = 0;
  REP(i,n-1) ans = max(ans,l[i]+r[i+1]);
  cout << ans << endl;
  return 0;
}
