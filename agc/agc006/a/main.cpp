#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)

int main() {
  int n;
  string s,t;
  cin >> n >> s >> t;

  REP(i,n) {
    if (s.substr(i) == t.substr(0,n-i)) {
      cout << n+i << endl;
      return 0;
    }
  }

  cout << n*2 << endl;
  return 0;
}