#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n,m; cin >> n >> m;
  vector<string> s(n);
  REP(i,n) cin >> s[i];
  set<string> st;
  REP(i,m) {
    string t; cin >> t;
    st.insert(t);
  }
  int tot = 0;
  REP(i,n) tot += s[i].size();
  int rem = 16 - tot;
  vector<int> b(n);
  iota(b.begin(),b.end(),0);

  do {
    auto dfs = [&](auto self, int i, int rem, string t) {
      t += s[b[i]];
      if ((int)t.size() > 16) return;
      if (i == n-1) {
        if (3 <= (int)t.size() && st.find(t) == st.end()) { cout << t << endl; exit(0); }
        return;
      }

      REP(j,rem) {
        t += '_';
        self(self,i+1,rem-(j+1),t);
      }
    };
    dfs(dfs,0,rem,"");
  } while (next_permutation(b.begin(), b.end()));

  cout << -1 << endl;
  return 0;
}