#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'

int main() {
  int n,c; cin >> n >> c;
  vector<int> d(2); // 000..., 111...
  d[1] = (1<<30)-1;
  REP(i,n) {
    int t,a; cin >> t >> a;
    REP(j,2) {
      if (t == 1) d[j] &= a;
      if (t == 2) d[j] |= a;
      if (t == 3) d[j] ^= a;
    }
    c = (c & d[1]) | (~c & d[0]);
    cout << c << endl;
  }
  return 0;
}