#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)

int main() {
  string s;
  int n,q;
  cin >> n >> s >> q;

  bool r = false;
  int t,a,b;
  REP(i,q) {
    cin >> t >> a >> b;
    a--; b--;

    if (t == 1) {
      if (r) {
        a = a < n ? a+n : a-n;
        b = b < n ? b+n : b-n;
      }
      swap(s[a],s[b]);
    } else {
      r = !r;
    }
  }

  if (r) s = s.substr(n) + s.substr(0,n);
  cout << s << endl;
  return 0;
}