#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int h,w,n; cin >> h >> w >> n;
  vector row(h,vector<int>());
  vector col(w,vector<int>());
  vector<int> rowdel(h);
  vector<int> coldel(w);
  REP(i,n) {
    int x,y; cin >> x >> y; x--; y--;
    row[x].push_back(y);
    col[y].push_back(x);
  }

  int q; cin >> q;
  REP(_,q) {
    int t,x; cin >> t >> x; x--;
    if (t == 2) { swap(row,col); swap(rowdel,coldel); }

    int ans = max(0, (int)row[x].size() - rowdel[x]);
    cout << ans << endl;
    for(auto v: row[x]) coldel[v]++;
    row[x].clear();

    if (t == 2) { swap(row,col); swap(rowdel,coldel); }
  }
  return 0;
}