#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n,q; cin >> n >> q;
  vector<int> a(n);
  REP(i,n) cin >> a[i];
  int scnt = 0;
  REP(_,q) {
    int t,x,y; cin >> t >> x >> y;
    x--; y--;
    x = (x-scnt+n) % n;
    y = (y-scnt+n) % n;
    if (t == 1) swap(a[x],a[y]);
    else if (t == 2) scnt = (scnt+1)%n;
    else cout << a[x] << endl;
  }
  return 0;
}