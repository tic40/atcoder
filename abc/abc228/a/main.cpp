#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(int)(n);i++)

int main() {
  int s,t,x;
  cin >> s >> t >> x;

  if (s <= t) {
    if (s <= x && x < t) {
      cout << "Yes" << endl;
    } else {
      cout << "No" << endl;
    }
  } else {
    if (s <= x) {
      cout << "Yes" << endl;
    } else if (x < t) {
      cout << "Yes" << endl;
    } else {
      cout << "No" << endl;
    }
  }

  return 0;
}