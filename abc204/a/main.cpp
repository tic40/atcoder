#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)

int main() {
  int x,y; cin >> x >> y;
  if (x == y) {
    cout << x << endl;
  } else {
    if (x != 0 && y != 0) {
      cout << 0 << endl;
    } else if (x != 1 && y != 1) {
      cout << 1 << endl;
    } else if (x != 2 && y != 2) {
      cout << 2 << endl;
    }
  }

  return 0;
}