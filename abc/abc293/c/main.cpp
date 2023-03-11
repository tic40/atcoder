#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int h,w; cin >> h >> w;
  vector a(h,vector<int>(w));
  REP(i,h) REP(j,w) cin >> a[i][j];

  auto dfs = [&](int x, int y, unordered_set<int> st, auto dfs) {
    if (x >= h || y >= w) return 0;
    if (st.count(a[x][y])) return 0;
    if (x == h-1 && y == w-1) return 1;
    st.insert(a[x][y]);

    return dfs(x+1,y,st,dfs) + dfs(x,y+1,st,dfs);
  };

  cout << dfs(0,0,unordered_set<int>(),dfs) << endl;
  return 0;
}