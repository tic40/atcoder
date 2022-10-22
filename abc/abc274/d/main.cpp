#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'

int main() {
  int n,x,y; cin >> n >> x >> y;
  vector<int> a(n);
  REP(i,n) cin >> a[i];

  vector<bool> vx(1e4+1),vy(1e4+1); // x,yそれぞれまでの距離
  vx[abs(x-a[0])] = true;
  vy[abs(y)] = true;

  for(int i = 1; i < n; i++) {
    vector<bool> vp(1e4+1);
    if (i % 2 == 0) {
      swap(vx,vp);
      REP(j, 1e4+1) {
        if (vp[j]) {
          vx[j+a[i]] = true;
          vx[abs(j-a[i])] = true;
        }
      }
    } else {
      swap(vy,vp);
      REP(j, 1e4+1) {
        if (vp[j]) {
          vy[j+a[i]] = true;
          vy[abs(j-a[i])] = true;
        }
      }
    }
  }

  if (vx[0] && vy[0]) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}