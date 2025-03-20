#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

struct List { int prev,next; };

int main() {
  int n,q; cin >> n >> q;
  vector<List> list;
  REP(i,n) list.push_back(List{-1,-1});
  REP(i,q) {
    int t; cin >> t;
    if (t == 1) {
      int x,y; cin >> x >> y; x--; y--;
      list[x].next = y;
      list[y].prev = x;
    }
    if (t == 2) {
      int x,y; cin >> x >> y; x--; y--;
      list[x].next = -1;
      list[y].prev = -1;
    }
    if (t == 3) {
      int x; cin >> x; x--;
      vector<int> ans;
      while(list[x].prev != -1) { x = list[x].prev; }
      ans.push_back(x);
      while(list[x].next != -1) {
        x = list[x].next;
        ans.push_back(x);
      }
      cout << ans.size() << " ";
      for(auto v: ans) cout << v+1 << " ";
      cout << endl;
    }
  }
  return 0;
}
