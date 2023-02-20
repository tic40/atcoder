#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n,q; cin >> n >> q;
  vector<int> a(n);
  iota(a.begin(),a.end(),1);

  bool rev = false;
  REP(_,q) {
    int t; cin >> t;
    if (t == 1) {
      int x,y; cin >> x >> y;
      x--;
      if (rev) x = n-1-x;
      a[x] = y;
    } else if (t == 2) {
      rev = !rev;
    } else {
      int x; cin >> x;
      x--;
      if (rev) x = n-1-x;
      cout << a[x] << endl;
    }
  }
  return 0;
}