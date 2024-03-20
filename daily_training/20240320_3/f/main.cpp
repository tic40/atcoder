#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int h,w; cin >> h >> w;
  vector a(h,vector<int>(w));
  REP(i,h) REP(j,w) cin >> a[i][j];

  auto dfs = [&](auto self, int x, int y, unordered_set<int> st) {
    if (x >= h || y >= w) return 0;
    if (st.find(a[x][y]) != st.end()) return 0;
    st.insert(a[x][y]);
    if (x == h-1 && y == w-1) return 1;
    return self(self,x+1,y,st) + self(self,x,y+1,st);
  };

  cout << dfs(dfs,0,0,unordered_set<int>()) << endl;
  return 0;
}