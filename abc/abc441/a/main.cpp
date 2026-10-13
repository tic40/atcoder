#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int p,q,x,y; cin >> p >> q >> x >> y;
  bool ok = p <= x && x < p+100 && q <= y && y < q+100;
  cout << (ok ? "Yes" : "No") << endl;
  return 0;
}
