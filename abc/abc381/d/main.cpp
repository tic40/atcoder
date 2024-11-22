#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using P = pair<int,int>;

int main() {
  int n; cin >> n;
  vector<int> a(n);
  REP(i,n) cin >> a[i];

  vector<P> vs;
  REP(i,n) {
    if (vs.size() && vs.back().first == a[i]) vs.back().second++;
    else vs.emplace_back(a[i],1);
  }

  int sz = vs.size();
  int ans = 0;
  int r = 0;
  set<int> st;
  REP(l,sz) {
    while(r<sz) {
      if (l+1 < r && vs[r-1].second > 2) break;
      if (vs[r].second == 1) break;
      if (st.find(vs[r].first) != st.end()) break;
      st.insert(vs[r].first);
      r++;
    }

    ans = max(ans, (r-l)*2);
    st.erase(vs[l].first);
    if (r==l) r++;
  }
  cout << ans << endl;
  return 0;
}