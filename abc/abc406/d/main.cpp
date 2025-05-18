#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int h,w,n; cin >> h >> w >> n;
  vector<set<int>> row(h), col(w);
  REP(i,n) {
    int x,y; cin >> x >> y; x--; y--;
    row[x].insert(y);
    col[y].insert(x);
  }

  int q; cin >> q;
  REP(_,q) {
    int t,x; cin >> t >> x; x--;
    if (t == 1) {
      cout << row[x].size() << endl;
      for(auto v: row[x]) col[v].erase(x);
      row[x].clear();
    }
    if (t == 2) {
      cout << col[x].size() << endl;
      for(auto v: col[x]) row[v].erase(x);
      col[x].clear();
    }
  }
  return 0;
}