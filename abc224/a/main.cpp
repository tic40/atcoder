#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(int)(n);i++)

int main() {
  string s; cin >> s;
  if ( s.substr(s.size() - 2) == "er" ) cout << "er" << endl;
  else cout << "ist" << endl;

  return 0;
}