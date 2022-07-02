#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)

int main() {
  int n,q;
  string s;
  cin >> n >> q >> s;

  int rotated = 0;
  REP(i,q) {
    int t,x; cin >> t >> x;
    if (t == 1) {
      rotated += x;
    } else {
      rotated %= n;
      x--;
      int pos = (x - rotated + n) % n;
      cout << s[pos] << endl;
    }
  }
  return 0;
}