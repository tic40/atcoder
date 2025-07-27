#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  string s; cin >> s;
  int bit = 0;
  REP(i,(int)s.size()) {
    if (s[i] == '#') {
      bit |= 1;
      if (bit == 3) bit = 0;
    } else {
      if (!(bit>>1 & 1)) {
        bit |= 2;
        s[i] = 'o';
      }
    }
  }
  cout << s << endl;
  return 0;
}