#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int q; cin >> q;
  int p = 0, v = 0;
  REP(_,q) {
    int a; cin >> a;
    if (a == 1) v++;
    if (a == 2) v = max(0,v-1);
    if (a == 3) p = !p;
    cout << (v >= 3 && p ? "Yes" : "No") << endl;
  }
  return 0;
}
