#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'

int main() {
  int n,x,y; cin >> n >> x >> y;
  vector<int> a(n);
  REP(i,n) cin >> a[i];

  set<int> sx,sy;
  sx.insert(a[0]);
  sy.insert(0);
  for(int i = 1; i < n; i++) {
    set<int> t,p;
    i % 2 == 0 ? swap(p,sx) : swap(p,sy);
    for(int v: p) {
      t.insert(v+a[i]);
      t.insert(v-a[i]);
    }
    i % 2 == 0 ? swap(t,sx) : swap(t,sy);
  }

  cout << (sx.count(x) && sy.count(y) ? "Yes" : "No") << endl;
  return 0;
}