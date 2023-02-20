#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n; cin >> n;
  vector a(n,vector<int>(n));
  REP(i,n) REP(j,n) cin >> a[i][j];

  int q; cin >> q;
  REP(_,q) {
    int t,x,y;
    cin >> t >> x >> y;
    x--; y--;
    if (t == 1) swap(a[x],a[y]);
    else cout << a[x][y] << endl;
  }
  return 0;
}