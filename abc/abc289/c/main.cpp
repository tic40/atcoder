#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n,m; cin >> n >> m;
  vector<vector<int>> a(m);
  REP(i,m) {
    int c; cin >> c;
    REP(j,c) {
      int x; cin >> x;
      a[i].push_back(x);
    }
  }

  int ans = 0;
  REP(bit,1<<m) {
    unordered_set<int> st;
    REP(i,m) {
      if (bit >> i & 1) {
        for(int v: a[i]) st.insert(v);
      }
    }
    if ((int)st.size() == n) ans++;
  }
  cout << ans << endl;
  return 0;
}