#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n; cin >> n;
  vector<int> a(n);
  REP(i,n) cin >> a[i];

  auto f = [&](vector<int>& a) {
    unordered_set<int> st;
    vector<int> res(n);
    REP(i,n) {
      st.insert(a[i]);
      res[i] = st.size();
    }
    return res;
  };

  auto l = f(a);
  reverse(a.begin(),a.end());
  auto r = f(a);

  int ans = 0;
  REP(i,n-1) ans = max(ans,l[i]+r[n-i-2]);
  cout << ans << endl;
  return 0;
}
