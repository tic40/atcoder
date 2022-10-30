#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'
using P = pair<int,int>;

int main() {
  const int n = 9;
  vector<string> s(n);
  REP(i,n) cin >> s[i];
  set<P> st;
  vector<P> ps;
  REP(i,n) REP(j,n) {
    if (s[i][j] == '#') {
      st.emplace(i,j);
      ps.emplace_back(i,j);
    }
  }

  int ans = 0;
  for(auto a: ps) for(auto b: ps) {
    if (a == b) continue;
    int di = b.first - a.first;
    int dj = b.second - a.second;
    P c(b.first - dj, b.second + di);
    P d(c.first - di, c.second - dj);
    if (st.count(c) && st.count(d)) ans++;
  }

  cout << ans/4 << endl;
  return 0;
}