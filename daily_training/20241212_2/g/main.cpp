#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n,k; cin >> n >> k;
  vector<int> p(n);
  REP(i,n) cin >> p[i];

  set<int> st;
  REP(i,n) {
    st.insert(p[i]);
    if ((int)st.size() > k) st.erase(st.begin());
    if (i >= k-1) cout << *st.begin() << endl;
  }
  return 0;
}