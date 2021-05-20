#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)

int n,q;
vector<int> a,t,x,y;

void solve() {
  int shift = 0;
  REP(i,q) {
    int cx = x[i] - shift;
    int cy = y[i] - shift;
    if (cx < 0) cx += n;
    if (cy < 0) cy += n;

    if (t[i] == 1) swap( a[cx], a[cy]);
    else if (t[i] == 2) shift = (shift+1) % n;
    else cout << a[cx] << endl;
  }
  return;
}

int main() {
  cin >> n >> q;
  a.resize(n);
  REP(i,n) cin >> a[i];

  t.resize(q); x.resize(q); y.resize(q);
  REP(i,q) {
    cin >> t[i] >> x[i] >> y[i];
    x[i]--, y[i]--;
  }

  solve();
  return 0;
}