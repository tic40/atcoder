#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n,m,q; cin >> n >> m >> q;
  vector a(n,unordered_set<int>());
  vector<int> all(n);
  REP(_,q) {
    int t; cin >> t;
    if (t == 1) {
      int x,y; cin >> x >> y; x--; y--;
      a[x].insert(y);
    }
    if (t == 2) {
      int x; cin >> x; x--;;
      all[x]=1;
    }
    if (t == 3) {
      int x,y; cin >> x >> y; x--; y--;
      cout << (all[x] || a[x].count(y) ? "Yes" : "No") << endl;
    }
  }
  return 0;
}